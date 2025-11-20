/*======================================================
    Cross-Platform Graphics Library
    Portable version of the original Windows-only GraphicsLib
    
    Compatible with Windows, macOS, and Linux
    Uses SDL3 (version 3.2.22) for cross-platform graphics support
    
    Original by Tanzawa (2012/04/17)
    Cross-platform adaptation with SDL3
=======================================================*/

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Platform detection
#if defined(_WIN32) || defined(_WIN64) || defined(__WINDOWS__)
    #define PLATFORM_WINDOWS
    #define PLATFORM_NAME "Windows"
#elif defined(__APPLE__) || defined(__MACH__)
    #define PLATFORM_MACOS
    #define PLATFORM_NAME "macOS"
#elif defined(__linux__) || defined(__unix__)
    #define PLATFORM_LINUX
    #define PLATFORM_NAME "Linux"
#else
    #define PLATFORM_UNKNOWN
    #define PLATFORM_NAME "Unknown"
#endif

// Window dimensions (same as original)
#define WIN_WIDTH       640     // Window width
#define WIN_HEIGHT      480     // Window height

// Point structure (same as original)
typedef struct
{
    short x;
    short y;
} Point;

// Color definitions (RGB format, same as original)
#define COLOR_BLACK     0x000000    // Black
#define COLOR_RED       0xFF0000    // Red  
#define COLOR_GREEN     0x00FF00    // Green
#define COLOR_BLUE      0x0000FF    // Blue
#define COLOR_WHITE     0xFFFFFF    // White
#define COLOR_GRAY      0x808080    // Gray
#define COLOR_CYAN      0x00FFFF    // Cyan
#define COLOR_YELLOW    0xFFFF00    // Yellow
#define COLOR_MAGENTA   0xFF00FF    // Magenta

// Function declarations (same API as original)

/*======================================================
    Initialize graphics window
    Must be called before using any drawing functions
======================================================*/
void InitGraphicsWindow(void);

/*======================================================
    Close graphics window and cleanup resources
======================================================*/
void CloseGraphicsWindow(void);

/*======================================================
    Draw a pixel at specified coordinates with specified color
    
    Parameters:
        x     : x-coordinate of the pixel
        y     : y-coordinate of the pixel  
        color : color of the pixel (RGB format)
    
    Returns:
        0 : Success
        -1: Graphics window not initialized
======================================================*/
int Win_SetPixel(int x, int y, long color);

/*======================================================
    Fill a rectangle with specified color
    
    Parameters:
        sx     : x-coordinate of top-left corner
        sy     : y-coordinate of top-left corner
        width  : width of rectangle
        height : height of rectangle
        color  : fill color (RGB format)
    
    Returns:
        0 : Success
        -1: Graphics window not initialized
======================================================*/
int Win_FillRect(int sx, int sy, int width, int height, long color);

/*======================================================
    Draw a line between two points
    
    Parameters:
        sx    : x-coordinate of start point
        sy    : y-coordinate of start point
        ex    : x-coordinate of end point
        ey    : y-coordinate of end point
        color : line color (RGB format)
    
    Returns:
        0 : Success
        -1: Graphics window not initialized
======================================================*/
int Win_Line(int sx, int sy, int ex, int ey, long color);

/*======================================================
    Draw a filled circle
    
    Parameters:
        cx    : x-coordinate of center
        cy    : y-coordinate of center
        r     : radius
        color : fill color (RGB format)
    
    Returns:
        0 : Success
        -1: Graphics window not initialized
======================================================*/
int Win_FillCircle(int cx, int cy, int r, long color);

/*======================================================
    Draw a circle outline
    
    Parameters:
        cx    : x-coordinate of center
        cy    : y-coordinate of center
        r     : radius
        color : line color (RGB format)
    
    Returns:
        0 : Success
        -1: Graphics window not initialized
======================================================*/
int Win_Circle(int cx, int cy, int r, long color);

/*======================================================
    Draw text at specified position
    
    Parameters:
        sx    : x-coordinate for text
        sy    : y-coordinate for text
        size  : font size
        color : text color (RGB format)
        str   : text string to draw
    
    Returns:
        0 : Success
        -1: Graphics window not initialized
======================================================*/
int Win_DrawText(int sx, int sy, int size, long color, char str[]);

/*======================================================
    Check if left mouse button was clicked
    
    Parameters:
        xPos : pointer to store x-coordinate of click
        yPos : pointer to store y-coordinate of click
    
    Returns:
        0 : No click detected
        1 : Click detected (coordinates stored in xPos, yPos)
        -1: Graphics window not initialized
======================================================*/
int Win_Get_L_MouseDownPos(int *xPos, int *yPos);

/*======================================================
    Check if right mouse button was clicked
    
    Parameters:
        xPos : pointer to store x-coordinate of click
        yPos : pointer to store y-coordinate of click
    
    Returns:
        0 : No click detected
        1 : Click detected (coordinates stored in xPos, yPos)
        -1: Graphics window not initialized
======================================================*/
int Win_Get_R_MouseDownPos(int *xPos, int *yPos);

/*======================================================
    Update the display (call this regularly in your main loop)
    
    Returns:
        1 : Window still open, continue running
        0 : Window closed, should exit program
======================================================*/
int UpdateDisplay(void);

/*======================================================
    Sleep for specified milliseconds
    Cross-platform sleep function
    
    Parameters:
        ms : milliseconds to sleep
======================================================*/
void CrossPlatformSleep(int ms);

#ifdef __cplusplus
}
#endif