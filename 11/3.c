#include <stdio.h>

// 行列A（m×n）と行列B（n×p）を入力し、その積C = A × B を計算して表示するプログラムを作成してください。
int main()
{
    int m, n, p;
    printf("=== 行列の積計算プログラム ===\n行列A: m x n, 行列B: n x p の積 C = A × B を計算します\n\n");

    printf("行列Aの行数mを入力してください: ");
    scanf("%d", &m);
    if (m < 1 || m > 4)
    {
        printf("エラー: 1以上4以下の整数を入力してください\n");
        return 1;
    }
    printf("行列Aの列数n（=行列Bの行数）を入力してください:");
    scanf("%d", &n);
    if (n < 1 || n > 4)
    {
        printf("エラー: 1以上4以下の整数を入力してください\n");
        return 1;
    }
    printf("行列Bの列数pを入力してください:");
    scanf("%d", &p);
    if (p < 1 || p > 4)
    {
        printf("エラー: 1以上4以下の整数を入力してください\n");
        return 1;
    }
    printf("行列A (%d x %d) の要素を入力してください:\n", m, n);
    int A[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("行列B (%d x %d) の要素を入力してください:\n", n, p);
    int B[n][p];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }
    printf("--- 行列A (%d x %d) ---\n", m, n);
    for (int i = 0; i < m; i++)
    {
        printf("   ");
        for (int j = 0; j < n; j++)
            printf("%d   ", A[i][j]);
        printf("\n");
    }
    printf("--- 行列B (%d x %d) ---\n", n, p);
    for (int i = 0; i < n; i++)
    {
        printf("   ");
        for (int j = 0; j < p; j++)
            printf("%d   ", B[i][j]);
        printf("\n");
    }

    int C[m][p];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("--- 行列C (%d x %d) ---\n", m, p);
    for (int i = 0; i < m; i++)
    {
        printf("   ");
        for (int j = 0; j < p; j++)
            printf("%d   ", C[i][j]);
        printf("\n");
    }

    printf("詳細表示:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            printf("C[%d][%d] = %d\n", i, j, C[i][j]);
        }
    }
}