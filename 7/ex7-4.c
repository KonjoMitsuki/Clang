#include <stdio.h>

int main(void) {
    int i = 0;
    int res = 0;
    while(i <= 100){
        if((i % 13) == 2 || (i % 7) == 3){
            res ++;
            // printf("i = %d\n", i); 
        }
        i++;
    }
    printf("合計 %d 個\n", res);
}
