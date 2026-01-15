#include <linux/limits.h>
#include <stdio.h>

int main(){
	int vec[4];
	int i =0;
	do {
		printf("数字を入力してください: ");
		scanf("%d",&vec[i]);	
		i++;
	}while (i<4);
	// 計算
	int sum =0;
	for(int i=0;i<4;i++){
		sum += vec[i];
	}
	double avg = sum/4.0;
	printf("平均値:%.2lf\n",avg);
}
