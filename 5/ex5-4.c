#include<stdio.h>

int main() {
    int a;
    printf("0以上100以下の値を入力してください\n");
    scanf("%d", &a);

    if(a >= 0 && a <= 100){
        printf("aの値は正しく入力されました\n");
    }else{
        printf("範囲外の値が入力されました\n");
    }
    getchar();
    return 0;
}