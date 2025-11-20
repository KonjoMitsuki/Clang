#include <stdio.h>
#include "GraphicsLib.h"

int main()
{
    
    InitGraphicsWindow();
    // TODO: while(UpdateDisplay())ループを実装してください
    int x = 40, y = 40;
    int row =0, col = 0;
    // int r = 30;
    int num = 0;
    int offset = num % 8;
    long  color[8] = {COLOR_RED, COLOR_BLUE, COLOR_GREEN, 
                    COLOR_YELLOW, COLOR_CYAN, COLOR_MAGENTA, 
                    COLOR_WHITE, COLOR_BLACK};
    while(row < 6){
        col = 0;
        while(col < 8){
            Win_FillCircle(x,y,30,color[offset]);
            col++;
            num++;
            x = 40 + col * 80;
        }
        y = 40 + row * 80;
        row++;
    }

    
    while(UpdateDisplay()) {
        CrossPlatformSleep(10); 
    }

    printf("プログラムを終了します\n");
    CloseGraphicsWindow();
    return 0;
}