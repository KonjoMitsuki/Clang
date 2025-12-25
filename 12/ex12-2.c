#include <stdio.h>

int calc_sum(int a, int b) {
    return a + b;
}

int main() {
    int x, y, z;
    printf("\n 1つ目の数字を入力してください ");
    scanf("%d", &x);
    printf("\n 2つ目の数字を入力してください ");
    scanf("%d", &y);
    z = calc_sum(x, y);
    printf("2つの数字の合計は%dです\n", z);
    return 0;
}