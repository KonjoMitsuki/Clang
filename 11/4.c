#include <stdio.h>

int main(void)
{
    int n;
    printf("=== 魔方陣判定プログラム ===\n");
    printf("n x n の正方行列が魔方陣かどうかを判定します\n\n");

    printf("行列のサイズnを入力してください: ");
    if (scanf("%d", &n) != 1)
        return 1;

    if (n < 1 || n > 5)
    {
        printf("エラー: 1以上5以下の整数を入力してください\n");
        return 1;
    }

    int matrix[5][5] = {0};
    int row_sum[5] = {0};
    int col_sum[5] = {0};
    int diag1_sum = 0;
    int diag2_sum = 0;

    printf("\n行列 (%d x %d) の要素を入力してください:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("matrix[%d][%d]: ", i, j);
            if (scanf("%d", &matrix[i][j]) != 1)
                return 1;
        }
    }

    printf("\n--- 入力行列 (%d x %d) ---\n", n, n);
    for (int i = 0; i < n; i++)
    {
        printf("   ");
        for (int j = 0; j < n; j++)
        {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = 0; j < n; j++)
        {
            s += matrix[i][j];
        }
        row_sum[i] = s;
    }

    for (int j = 0; j < n; j++)
    {
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            s += matrix[i][j];
        }
        col_sum[j] = s;
    }

    for (int i = 0; i < n; i++)
    {
        diag1_sum += matrix[i][i];
        diag2_sum += matrix[i][n - 1 - i];
    }

    printf("\n--- 行の合計 ---\n");
    for (int i = 0; i < n; i++)
    {
        printf("row_sum[%d] = %d\n", i, row_sum[i]);
    }

    printf("\n--- 列の合計 ---\n");
    for (int j = 0; j < n; j++)
    {
        printf("col_sum[%d] = %d\n", j, col_sum[j]);
    }


    printf("\n--- 対角線の合計 ---\n");
    printf("diag1_sum = %d\n", diag1_sum);
    printf("diag2_sum = %d\n", diag2_sum);

    /* 判定 */
    int magic_sum = row_sum[0];
    int is_magic = 1;

    for (int i = 0; i < n; i++)
    {
        if (row_sum[i] != magic_sum)
        {
            is_magic = 0;
            break;
        }
    }

    if (is_magic)
    {
        for (int j = 0; j < n; j++)
        {
            if (col_sum[j] != magic_sum)
            {
                is_magic = 0;
                break;
            }
        }
    }

    if (is_magic)
    {
        if (diag1_sum != magic_sum || diag2_sum != magic_sum)
            is_magic = 0;
    }

    /* 結果表示 */
    printf("\n--- 判定結果 ---\n");
    printf("magic_sum = %d\n", magic_sum);
    printf("is_magic = %d\n", is_magic);

    if (is_magic)
    {
        printf("この行列は魔方陣です！\n");
    }
    else
    {
        printf("この行列は魔方陣ではありません\n");
    }

    return 0;
}