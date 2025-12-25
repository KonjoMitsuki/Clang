#include<stdio.h>

int main(){
    int n;
    printf("=== 九九の表プログラム ===\n表のサイズnを入力してください:");
    scanf("%d",&n);
    if(n>9||n<1){
        printf("エラー: 1以上9以下の整数を入力してください");
        return 1;
    }
    printf("九九の表を作成しました。");

    printf("--- 九九の表 (%d x %d) ---\n",n,n);
    int table[n][n];
    for(int i=0;i<n;i++){
        printf("   ");
        for(int j=0;j<n;j++){
            table[i][j] = (i+1) * (j+1);
            printf("%d   ",table[i][j]);
        }
        printf("\n");
    }
    printf("\n詳細表示:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("table[%d][%d] = %d\n",i,j,table[i][j]);
        }
    }

}