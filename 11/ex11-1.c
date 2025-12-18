#include <stdio.h>

int main()
{
    int x[7][5];
    int i, j;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++) {
            x[i][j] = i * 10 + j;
        }
    }
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++) {
            printf("X[%d][%d]=%d\n", i,j , x[i][j]);
        }
    }
    
    return 0;
}