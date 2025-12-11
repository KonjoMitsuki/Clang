#include<stdio.h>

int main(){
    int n;
    int max = 0,min=100000,max_i,min_i,sum=0,even=0,odd =0;
    double avg;
    printf("=== 配列統計計算プログラム ===\nデータの個数を入力してください:");
    scanf("%d",&n);
    if(n < 1||n >20){
        printf("エラー: 1以上20以下の整数を入力してください\n");
        return 1;
    }
    int x[n];
    // 入力
    printf("5個の整数を入力してください:\n");
    for(int i=0;i<n;i++){
        printf("データ%d:n", i+1);
        scanf("%d",&x[i]);
        sum += x[i];

        if(x[i] %2==0)even++;
        else odd++;
        if(max < x[i]){
            max = x[i];
            max_i = i;
        }
        if(min >x[i]){
            min=x[i];
            min_i = i;
        }
    }
    //出力
    printf("入力されたデータ:\n");
    for(int i=0;i<n;i++){
        printf("X[%d]= %d\n", i, x[i]);
    }
    //統計
    avg = (double)sum /n;
    printf("--- 統計結果 ---\n");
    printf("合計: %d\n",sum);
    printf("平均: %.2lf\n",avg);
    printf("最大値: %d (インデックス: %d)\n",max,max_i);
    printf("最小値: %d (インデックス: %d)\n",min,min_i);
    printf("偶数の個数: %d\n",even);
    printf("奇数の個数: %d\n",odd);
    for(int i =0;i<n;i++){}

    



}