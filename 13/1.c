#include<stdio.h>


int f(int num){
    num--;
    for(int i=0;i<3;i++){
        num++;
        printf("カウント: %d\n",num);
    }
    return num;
}
int main(){
    int n;
    printf("カウント開始値を入力してください: ");
    scanf("%d",&n);
    if(n<0 || n>100){
        printf("0以上100以下の整数を入力してください。\n");
        return 1;
    }
    printf("--- 1回目の呼び出し ---\n");
    int result = f(n);
    printf("結果: %d \n",result);
        printf("--- 2回目の呼び出し ---\n");
    int result2 = f(n);
    printf("結果: %d \n",result2);
    return 0;
}