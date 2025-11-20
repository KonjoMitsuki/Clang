#include <stdio.h>

int main(){
    int count = 0;
    for(int i = 0; i <= 100; i++){
        if(i % 17 == 5 || i % 11 == 2){
            printf("%d\n", i);
            count++;
        }
    }
    printf("個数 = %d\n", count);
    return 0;
}