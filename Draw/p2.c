#include <stdio.h>
#include "GraphicsLib.h" 

int main()
{
    InitGraphicsWindow();
    int a = 0,b= 1,next=0,n;
    int x,y;
    int direction, size;
    printf("=== フィボナッチ数列プログラム ===\n項数を入力してください:");
    scanf("%d",&n);
    if(n <=0){
        printf("エラー: 1以上の整数を入力してください\n");
        return 1;
    }
    printf("フィボナッチ数列の最初の5項:\n");

    for(int i = 0;i < n;i++){
        if(i == 0){
            // printf("%d\n",0);
        }
        else if(i == 1){
            next = 1;
            printf("正方形 1:Fib=%d\n, サイズ=5,  位置=(0, 0), 方向=0",1);
            Win_rect(0,0,next,next,COLOR_RED);
        }
        else{
            next = a + b;
            a = b;
            b = next;
            size = next*5;
            printf("%d \n",next);
        }
    }


    while(UpdateDisplay()) {
        CrossPlatformSleep(10); 
    }

    return 0;
}