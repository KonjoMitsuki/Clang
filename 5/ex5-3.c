#include <stdio.h>
int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    if (a < b)
    {
        printf("変数aの値は変数bの値より小さいです\n");
    }
    else if (a == b)
    {
        printf("変数aの値は変数bの値と等しいです\n");
    }
    else
    {
        printf("変数aの値は変数bの値より大きいです\n");
    }

    getchar();
    return 0;
}