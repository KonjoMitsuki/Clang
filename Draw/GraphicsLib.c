/*======================================================
    Cross-Platform Graphics Library Implementation
    Uses SDL3 (version 3.2.22) for cross-platform graphics support
    
    Compatible with Windows, macOS, and Linux
    Maintains same API as original Windows-only version
    Automatic platform detection and configuration
    
    Features automatic window updates (50ms timer, same as original)
    Timer-based automatic display refresh (matches WM_TIMER behavior)
=======================================================*/

#include "GraphicsLib.h"
#include <SDL3/SDL.h>
#include <math.h>

// Global variables for SDL
static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;
static SDL_Texture* backBuffer = NULL;

// Mouse state variables
static int leftMouseClicked = 0;
static int rightMouseClicked = 0;
static Point leftMousePos = {0, 0};
static Point rightMousePos = {0, 0};

// Window state
static int windowOpen = 1;
static int initialized = 0;

// Timer for automatic updates (matches original 50ms timer)
static SDL_TimerID updateTimerID = 0;

// Mutex for thread-safe drawing (replaces CRITICAL_SECTION)
static SDL_Mutex* drawMutex = NULL;

// Helper function to extract RGB components from color
static void ExtractRGB(long color, Uint8* r, Uint8* g, Uint8* b) {
    *r = (color >> 16) & 0xFF;
    *g = (color >> 8) & 0xFF;
    *b = color & 0xFF;
}

// Helper function to draw a pixel using SDL
static void DrawPixelSDL(SDL_Renderer* renderer, int x, int y) {
    SDL_RenderPoint(renderer, (float)x, (float)y);
}

// Bresenham's line algorithm helper
static void DrawLineBresenham(SDL_Renderer* renderer, int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
    
    while (1) {
        DrawPixelSDL(renderer, x0, y0);
        
        if (x0 == x1 && y0 == y1) break;
        
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

// Circle drawing using midpoint algorithm
static void DrawCircleOutline(SDL_Renderer* renderer, int cx, int cy, int r) {
    int x = r;
    int y = 0;
    int err = 0;
    
    while (x >= y) {
        DrawPixelSDL(renderer, cx + x, cy + y);
        DrawPixelSDL(renderer, cx + y, cy + x);
        DrawPixelSDL(renderer, cx - y, cy + x);
        DrawPixelSDL(renderer, cx - x, cy + y);
        DrawPixelSDL(renderer, cx - x, cy - y);
        DrawPixelSDL(renderer, cx - y, cy - x);
        DrawPixelSDL(renderer, cx + y, cy - x);
        DrawPixelSDL(renderer, cx + x, cy - y);
        
        if (err <= 0) {
            y += 1;
            err += 2 * y + 1;
        }
        
        if (err > 0) {
            x -= 1;
            err -= 2 * x + 1;
        }
    }
}

// Fill circle using horizontal lines
static void FillCircleSDL(SDL_Renderer* renderer, int cx, int cy, int r) {
    for (int y = -r; y <= r; y++) {
        int x = (int)sqrt(r * r - y * y);
        SDL_RenderLine(renderer, (float)(cx - x), (float)(cy + y), (float)(cx + x), (float)(cy + y));
    }
}

// Timer callback function - called every 50ms to update display automatically
// This matches the original Windows WM_TIMER implementation
static Uint32 TimerCallback(void* userdata, SDL_TimerID timerID, Uint32 interval) {
    (void)userdata;
    (void)timerID;
    
    // Push a custom event to update the display
    SDL_Event event;
    SDL_zero(event);
    event.type = SDL_EVENT_USER;
    SDL_PushEvent(&event);
    
    return interval;  // Continue timer with same interval
}

// Process events and update display
// Called by UpdateDisplay() - must be on main thread (macOS requirement)
static void ProcessEventsAndUpdate(void) {
    if (!initialized || !windowOpen) return;
    
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_EVENT_QUIT:
                windowOpen = 0;
                break;
                
            case SDL_EVENT_MOUSE_BUTTON_DOWN:
                if (e.button.button == SDL_BUTTON_LEFT) {
                    leftMousePos.x = (short)e.button.x;
                    leftMousePos.y = (short)e.button.y;
                    leftMouseClicked = 1;
                } else if (e.button.button == SDL_BUTTON_RIGHT) {
                    rightMousePos.x = (short)e.button.x;
                    rightMousePos.y = (short)e.button.y;
                    rightMouseClicked = 1;
                }
                break;
                
            case SDL_EVENT_USER:
                // Timer event - update display AUTOMATICALLY
                if (drawMutex) SDL_LockMutex(drawMutex);
                
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderClear(renderer);
                SDL_RenderTexture(renderer, backBuffer, NULL, NULL);
                SDL_RenderPresent(renderer);
                
                if (drawMutex) SDL_UnlockMutex(drawMutex);
                break;
        }
    }
}

// Initialize graphics window
void InitGraphicsWindow(void) {
    if (initialized) return;
    
    // SDL3 timers are always available, no need for SDL_INIT_TIMER flag
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return;
    }
    
    window = SDL_CreateWindow("Cross-Platform Graphics Window",
                             WIN_WIDTH, WIN_HEIGHT,
                             0);
    
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }
    
    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }
    
    // Create back buffer texture
    backBuffer = SDL_CreateTexture(renderer,
                                  SDL_PIXELFORMAT_RGBA8888,
                                  SDL_TEXTUREACCESS_TARGET,
                                  WIN_WIDTH, WIN_HEIGHT);
    
    // Clear the back buffer to white
    SDL_SetRenderTarget(renderer, backBuffer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderTarget(renderer, NULL);
    
    // Create mutex for thread-safe drawing (replaces Windows CRITICAL_SECTION)
    drawMutex = SDL_CreateMutex();
    if (drawMutex == NULL) {
        printf("Mutex could not be created! SDL_Error: %s\n", SDL_GetError());
    }
    
    initialized = 1;
    windowOpen = 1;
    
    // Start automatic update timer (50ms interval, same as original Windows version)
    // Original: SetTimer(hwnd, 100, 50, NULL)
    // Timer fires every 50ms and pushes SDL_EVENT_USER to trigger rendering
    updateTimerID = SDL_AddTimer(50, TimerCallback, NULL);
    if (updateTimerID == 0) {
        printf("Timer could not be created! SDL_Error: %s\n", SDL_GetError());
    }
}

// Close graphics window
void CloseGraphicsWindow(void) {
    if (!initialized) return;
    
    // Stop the timer (matches original KillTimer)
    if (updateTimerID != 0) {
        SDL_RemoveTimer(updateTimerID);
        updateTimerID = 0;
    }
    
    // Destroy mutex
    if (drawMutex) {
        SDL_DestroyMutex(drawMutex);
        drawMutex = NULL;
    }
    
    if (backBuffer) {
        SDL_DestroyTexture(backBuffer);
        backBuffer = NULL;
    }
    
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
    }
    
    if (window) {
        SDL_DestroyWindow(window);
        window = NULL;
    }
    
    SDL_Quit();
    
    initialized = 0;
    windowOpen = 0;
}

// Set pixel
int Win_SetPixel(int x, int y, long color) {
    if (!initialized) return -1;
    
    Uint8 r, g, b;
    ExtractRGB(color, &r, &g, &b);
    
    // Thread-safe drawing (replaces EnterCriticalSection)
    if (drawMutex) SDL_LockMutex(drawMutex);
    
    SDL_SetRenderTarget(renderer, backBuffer);
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    DrawPixelSDL(renderer, x, y);
    SDL_SetRenderTarget(renderer, NULL);
    
    if (drawMutex) SDL_UnlockMutex(drawMutex);
    
    return 0;
}

// Fill rectangle
int Win_FillRect(int sx, int sy, int width, int height, long color) {
    if (!initialized) return -1;
    
    Uint8 r, g, b;
    ExtractRGB(color, &r, &g, &b);
    
    SDL_FRect rect = {(float)sx, (float)sy, (float)width, (float)height};
    
    if (drawMutex) SDL_LockMutex(drawMutex);
    
    SDL_SetRenderTarget(renderer, backBuffer);
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderTarget(renderer, NULL);
    
    if (drawMutex) SDL_UnlockMutex(drawMutex);
    
    return 0;
}

// Draw line
int Win_Line(int sx, int sy, int ex, int ey, long color) {
    if (!initialized) return -1;
    
    Uint8 r, g, b;
    ExtractRGB(color, &r, &g, &b);
    
    if (drawMutex) SDL_LockMutex(drawMutex);
    
    SDL_SetRenderTarget(renderer, backBuffer);
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    DrawLineBresenham(renderer, sx, sy, ex, ey);
    SDL_SetRenderTarget(renderer, NULL);
    
    if (drawMutex) SDL_UnlockMutex(drawMutex);
    
    return 0;
}

// Fill circle
int Win_FillCircle(int cx, int cy, int r, long color) {
    if (!initialized) return -1;
    
    Uint8 red, green, blue;
    ExtractRGB(color, &red, &green, &blue);
    
    if (drawMutex) SDL_LockMutex(drawMutex);
    
    SDL_SetRenderTarget(renderer, backBuffer);
    SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
    FillCircleSDL(renderer, cx, cy, r);
    SDL_SetRenderTarget(renderer, NULL);
    
    if (drawMutex) SDL_UnlockMutex(drawMutex);
    
    return 0;
}

// Draw circle outline
int Win_Circle(int cx, int cy, int r, long color) {
    if (!initialized) return -1;
    
    Uint8 red, green, blue;
    ExtractRGB(color, &red, &green, &blue);
    
    if (drawMutex) SDL_LockMutex(drawMutex);
    
    SDL_SetRenderTarget(renderer, backBuffer);
    SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
    DrawCircleOutline(renderer, cx, cy, r);
    SDL_SetRenderTarget(renderer, NULL);
    
    if (drawMutex) SDL_UnlockMutex(drawMutex);
    
    return 0;
}

// Draw text - NOT IMPLEMENTED (would require SDL_ttf or platform-specific code)
// Original used Windows GDI for text rendering
// For cross-platform simplicity, text rendering is not implemented
int Win_DrawText(int sx, int sy, int size, long color, char str[]) {
    // Suppress unused parameter warnings
    (void)sx; (void)sy; (void)size; (void)color; (void)str;
    
    // Return -1 to indicate text rendering is not supported
    return -1;
}

// Get left mouse button state
int Win_Get_L_MouseDownPos(int *xPos, int *yPos) {
    if (!initialized) return -1;
    
    if (leftMouseClicked) {
        *xPos = leftMousePos.x;
        *yPos = leftMousePos.y;
        leftMouseClicked = 0;  // Reset flag
        return 1;
    }
    
    return 0;
}

// Get right mouse button state
int Win_Get_R_MouseDownPos(int *xPos, int *yPos) {
    if (!initialized) return -1;
    
    if (rightMouseClicked) {
        *xPos = rightMousePos.x;
        *yPos = rightMousePos.y;
        rightMouseClicked = 0;  // Reset flag
        return 1;
    }
    
    return 0;
}

// Update display and handle events
// Must be called in a loop (macOS requires event processing on main thread)
// The display refresh happens AUTOMATICALLY via 50ms timer
// This just processes events (including timer events that trigger rendering)
int UpdateDisplay(void) {
    if (!initialized) return 0;
    
    // Process events - timer will trigger automatic rendering every 50ms
    ProcessEventsAndUpdate();
    
    return windowOpen;
}

// Cross-platform sleep function
void CrossPlatformSleep(int ms) {
    SDL_Delay(ms);
}