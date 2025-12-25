#include <stdio.h>

int function(int x);

int main()
{
    int a = 0, b = 1;
    a = function(1);
    b = function(a);
    printf("a = %d, b = %dです\n", a, b);
    return 0;
}

int function(int x)
{
    printf("関数functionの引数の値は%dです\n", x);
    return x * 5;
}