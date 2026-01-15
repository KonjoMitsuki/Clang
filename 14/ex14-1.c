#include<stdio.h>

int culc_Conevol(double r,double h){
    double V, pi = 3.1315;
    V = (r*r*pi*h)/3;
    return V;
}
int main(){
    double r,h,volume;
    printf("底面の半径を入力してください:");
    scanf("%lf",&r);
    printf("高さを入力してください:");
    scanf("%lf",&h);
    volume = culc_Conevol(r,h);
    printf("円錐の体積は%.2fです\n",volume);
    return 0;

}