#include<stdio.h>

int main(){
    int n;
    printf("===配列初期化プログラム===\n配列のサイズを入力してください: ");
    scanf("%d", &n);
    if(n <= 0 || n > 100){
        printf("エラー: 1以上100以下の整数を入力してください\n");
        return 1;
    }
    printf("配列を初期化しました\n配列の内容:\n");
    int num[n];
    for(int i = 0; i < n;i++){
        num[i]=i;
    }
    for(int i = 0;i < n;i++){
        printf("X[%d] = %d\n", i, num[i]);
    }
}