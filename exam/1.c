#include <stdio.h>
#include "GraphicsLib.h"
#define BALL_SIZE 10

int main()
{

    InitGraphicsWindow();
    // 初期準備-------------------------

    //---------------------------------------
    while (UpdateDisplay()) {
	// 毎回更新-----------------------
	
	// -------------------------------
        CrossPlatformSleep(10);
    }

    printf("プログラムを終了します\n");
    CloseGraphicsWindow();
    return 0;
}
