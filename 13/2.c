#include<stdio.h>

int g_score = 0;

void add_point(int point){
	g_score += point;
}
int main(){
	int num;
	printf("1つ目の値を入力してください: ");
	scanf("%d",&num);
	if(num<1 || num>1000){
		printf("エラー: 1以上1000以下の整数を入力してください\n");
		return 1;
	}
	add_point(num);
	printf("累積合計: %d\n",g_score);
	
	printf("2つ目の値を入力してください: ");
	scanf("%d",&num);
	if(num<1 || num>1000){
		printf("エラー: 1以上1000以下の整数を入力してください\n");
		return 1;
	}
	add_point(num);
	printf("累積合計: %d\n",g_score);

	printf("3つ目の値を入力してください: ");
	scanf("%d",&num);
	if(num<1 || num>1000){
		printf("エラー: 1以上1000以下の整数を入力してください\n");
		return 1;
	}
	add_point(num);
	printf("累積合計: %d\n",g_score);

	printf("最終合計: %d\n",g_score);
}
