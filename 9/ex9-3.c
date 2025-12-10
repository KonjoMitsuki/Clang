#include<stdio.h>

int main(){
    int x[10],y[10];
    for(int i = 0;i < 10;i++){
        x[i] = i;

        printf("x[%d]=%d\n",i,x[i]);
    }   
    printf("配列xの各要素の２乗を配列ｙに代入   \n");
    for(int i = 0;i < 10;i++){
        y[i] = x[i] * x[i];
        printf("y[%d]=%d\n",i,y[i]);
    }
    return 0;

}