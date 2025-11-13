#include<stdio.h>

int main() {
    printf("コンピューターの英語が正解番号を入力してください\n");
    printf("\t1.conputar\n");
    printf("\t2.computor\n");
    printf("\t3.computer\n");

    int a;
    scanf("%d", &a);

    switch(a){
        case 1:
            printf("ぶー\n");
            break;
        case 2:
            printf("ぶー\n");
            break;
        case 3:
            printf("正解\n");
            break;
        default:
            printf("1~3の値を入力してください\n");
    }
    
    return 0;
}
