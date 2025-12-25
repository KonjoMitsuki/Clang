#include <stdio.h>

// //キーボードから入力された２つの整数型の値を引数とし，その合計値 を計算して戻り値として返す関数
// calc_sum( ) を生成し，その合計値 を画面上に表示するプログラムを完成させなさい．
// （ 関数の引数・戻り値に注意すること ）
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