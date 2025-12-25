#include <stdio.h>
#include <math.h>

double deg_to_rad(double degrees);
double calc_range(double v0, double angle_deg);
double calc_max_height(double v0, double angle_deg);

int main()
{
    double fv, angle_deg;
    printf("=== 斜方投射シミュレーション ===\n");
    printf("初速度(m/s)を入力してください: ");
    scanf("%lf", &fv);
    printf("投射角度(度)を入力してください: ");
    scanf("%lf", &angle_deg);
    if (fv < 1.0 || fv > 100.0)
    {
        printf("エラー: 初速度は1.0以上100.0以下で入力してください\n");
        return 1;
    }
    if (angle_deg < 1.0 || angle_deg > 89.0)
    {
        printf("エラー: 投射角度は1.0度以上89.0度以下で入力してください\n");
        return 1;
    }

    printf("--- 計算結果 ---\n");
    printf("飛距離: %.2lf m\n", calc_range(fv, angle_deg));
    printf("最高到達点: %.2lf m\n", calc_max_height(fv, angle_deg));

    return 0;
}

double calc_range(double v0, double angle_deg)
{
    double angle_rad = deg_to_rad(angle_deg);
    return (v0 * v0 * sin(2 * angle_rad)) / 9.8;
}

double calc_max_height(double v0, double angle_deg)
{
    double angle_rad = deg_to_rad(angle_deg);
    return (v0 * v0 * sin(angle_rad) * sin(angle_rad)) / (2 * 9.8);
}
double deg_to_rad(double degrees)
{
    return degrees * acos(-1.0) / 180.0;
}
