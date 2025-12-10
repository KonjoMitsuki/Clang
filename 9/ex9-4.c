#include<stdio.h>


int main(){
    
    int x[4];
    int sum = 0;
    for(int i = 0;i < 4;i++){
        printf("x[%d]=",i);
        scanf("%d",&x[i]);
        sum += x[i];
    }
    printf("合計値は%dです\n",sum);
    return 0;

}