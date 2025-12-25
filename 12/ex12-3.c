#include<stdio.h>

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