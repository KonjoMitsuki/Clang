#include<stdio.h>

// キー ボードから入力された３つの少数型の値を引数 とし，その値の平均値を計算する関数 calc_average3( ) 
// を生成し，その平均値を画面上 に表示するプログラムを指示に従い完成させなさい。
double calc_average3(double a, double b, double c);

int main(){
    double x, y, z, avg;
    printf("\n 1つ目の少数を入力してください ");
    scanf("%lf", &x);
    printf("\n 2つ目の少数を入力してください ");
    scanf("%lf", &y);
    printf("\n 3つ目の少数を入力してください ");
    scanf("%lf", &z);
    avg = calc_average3(x, y, z);
    printf("3つの少数の平均値は%.2lfです\n", avg);
    return 0;

}

double calc_average3(double a, double b, double c) {
    return (a + b + c) / 3.0;
}