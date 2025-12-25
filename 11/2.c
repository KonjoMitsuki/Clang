#include <stdio.h>
int main(){
    int m,n;
    printf("=== 行列加算プログラム ===\n行列A, B の行数mを入力してください:");
    scanf("%d",&m);
    if(m < 1 || m>5){
        printf("エラー: 1以上5以下の整数を入力してください");
        return 1;
    }
    printf("行列A, B の列数nを入力してください:");
    scanf("%d",&n);
    if(n < 1 || n>5){
        printf("エラー: 1以上5以下の整数を入力してください");
        return 1;
    }

    int A[m][n];
    printf("行列A (%d x %d) の要素を入力してください:\n",m,n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("A[%d][%d]: ",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    printf("\n");

    int B[m][n];
    printf("行列B (%d x %d) の要素を入力してください:",m,n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("B[%d][%d]: ",i,j);
            scanf("%d",&B[i][j]);
        }
    }
    printf("\n");

    printf("--- 行列A ---\n");
        for(int i=0;i<m;i++){
            printf("   ");
            for(int j=0;j<n;j++){
                printf("%d   ",A[i][j]);
            }
            printf("\n");
    }
    printf("\n");

    printf("--- 行列B ---\n");
    for(int i=0;i<m;i++){
        printf("   ");
        for(int j=0;j<n;j++){
            printf("%d   ",B[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int C[m][n];
    printf("--- 行列C = A + B ---\n");
    for(int i=0;i<m;i++){
        printf("   ");
        for(int j=0;j<n;j++){
            C[i][j] = A[i][j]+B[i][j];
            printf("%d   ",C[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("詳細表示:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("C[%d][%d] = %d\n",i,j,C[i][j]);
        }
    }
}