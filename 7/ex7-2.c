#include <stdio.h>

int main(void) {
    int i = 0;
    int input_number;
    printf("0以上の整数値を入力してください: ");
    scanf("%d", &input_number);
    if(input_number < 0) {
        printf("負の値です\n");
        return 0;
    }
    while (i <=  input_number){
        printf("i = %d\n", i);
        i++;
    }
    printf("おしまい\n");
}