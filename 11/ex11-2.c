#include<stdio.h>

int main(){
    int x[4][3] = {
        {0, 1, 2},
        {10, 11, 12},
        {20, 21, 22},
        {30, 31, 32}
    };
    int i, j;
    int sum = 0;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 3; j++){
            printf("X[%d][%d]=%d\n", i, j, x[i][j]);
            sum += x[i][j];
        }
    }
    double average = sum / 12.0;
    printf("平均値 = %.2f\n", average);    
    return 0;
}