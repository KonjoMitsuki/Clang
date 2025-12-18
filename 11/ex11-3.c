#include<stdio.h>


int main(){
    double A[2][2];
    int i, j;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            printf("A[%d][%d]の値は？ ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }
    double det = A[0][0] * A[1][1] - A[0][1] * A[1][0];
    printf("det(A)=%.1f です\n", det);
    return 0;

}