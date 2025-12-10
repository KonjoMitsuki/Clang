#include<stdio.h>

int main(){
    int x[15];
    for(int i = 0;i < 15;i++){
        x[i] = i;
        printf("x[%d]=%d\n",i,x[i]);
    }
    printf("各要素の20を加算^n");
    for(int i = 0;i < 15;i++){
        x[i] += 20;
        printf("x[%d]=%d\n",i,x[i]);
    }
    return 0;

}