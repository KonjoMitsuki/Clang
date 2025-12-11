#include <stdio.h>
#include "GraphicsLib.h"

int main()
{
    InitGraphicsWindow();

    int x = 200; 
    int y = 100; 
    // 方向 (0=右, 1=上, 2=左, 3=下)
    int direction = 0; 

    int fib[10] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

    // 描画に使用する色 (課題要件: 赤, 青, 緑 を最低2回ずつ使用)
    long colors[10] = {
        COLOR_RED, COLOR_BLUE, COLOR_GREEN,
        COLOR_RED, COLOR_BLUE, COLOR_GREEN,
        COLOR_YELLOW, COLOR_CYAN, COLOR_MAGENTA, COLOR_WHITE
    };

    for (int i = 0; i < 10; i++) {
        int current_fib = fib[i];
        int size = current_fib * 5;

        printf("正方形 %d: Fib=%d, サイズ=%d, 位置=(%d, %d), 方向=%d\n",
            i + 1, current_fib, size, x, y, direction);

        Win_FillRectangle(x, y, x + size, y + size, colors[i]);

        // 次の正方形の位置を計算し、方向を切り替える
        if (direction == 0) {       // 右 
            x += size;
        } else if (direction == 1) {  // 上 
            y -= size;
        } else if (direction == 2) {  // 左
            x -= size;
        } else if (direction == 3) {  // 下
            y += size;
        }

        // 方向を切り替え (0→1→2→3→0 の順)
        direction = (direction + 1) % 4;
    }


    while(UpdateDisplay()) {
        CrossPlatformSleep(10); 
    }

    printf("プログラムを終了します\n");
    CloseGraphicsWindow();
    return 0;
}