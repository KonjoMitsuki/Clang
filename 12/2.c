#include <stdio.h>

int is_prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    printf("整数を入力してください: ");
    int n;
    scanf("%d", &n);
    if (n < 2 || n > 1000)
    {
        printf("エラー: 2以上1000以下の整数を入力してください\n");
        return 1;
    }
    if (is_prime(n))
    {
        printf("%dは素数です\n", n);
    }
    else
    {
        printf("%dは素数ではありません\n", n);
    }
    return 0;
}