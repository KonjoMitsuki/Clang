#include<stdio.h>
double triangle_area(double base, double height){
    return base * height / 2.0;
}

int main(){
    double base, height, area;
    printf("底辺を入力してください: ");
    scanf("%lf", &base);
    printf("高さを入力してください: ");
    scanf("%lf", &height);
    if(height <= 0 || height > 100 || base <= 0 || base > 100){
        printf("エラー: 0より大きく100.0以下の数値を入力してください\n");
        return 1;
    }
    area = triangle_area(base, height);
    printf("面積=%.2lf", area);
    return 0;
}
