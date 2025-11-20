#include <stdio.h>

int main(){
    int sum = 0;
    for(int i = 100; i <= 300; i++)
        sum += i;
    printf("合計値 = %d\n", sum);
    return 0;
}