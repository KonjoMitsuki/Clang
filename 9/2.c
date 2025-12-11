#include <stdio.h>
int main(){
    int n;
    printf("=== 物体落下シミュレーション ===\nシミュレーション秒数を入力してください:");
    scanf("%d",&n);
    if(n <=0||n>10){
        printf("エラー: 1以上10以下の整数を入力してください");
        return 1;
    }
    double v[n+1];
    printf("落下距離を計算中...\n--- 計算結果 ---\n");
    for(int i =0;i<=n;i++){
        // h = (1/2) × g × t²
        v[i]= ((double)(1)/2) * 9.8 * i*i;
    }
    for(int i=0;i<=n;i++){
        printf("%d秒後: %.2lf m\n",i,v[i]);
    }
    printf("最終落下距離: %.2lf m\n",v[n]);
}