#include <stdio.h>

int main(){
    int n;
    int num = 1;

    printf("１以上の整数値を入力してください\n");
    scanf("%d", &n);

    if(n <= 0){
        printf("エラー\n");
    } else {
        for(int i = 1; i <= n; i++){
            num *= i;
        }
        printf("%d! = %d\n", n, num);
    }

    return 0;
}