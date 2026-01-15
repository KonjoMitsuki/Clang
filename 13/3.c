#include<stdio.h>

int get_id(){
	static int id = 0;
	id++;
	return id;
}
int main(){
	int n;
	printf("呼び出し回数を入力してください: ");
	scanf("%d", &n);
	for(int i=0;i < n;i++){
		printf("呼び出し回数: %d\n",get_id());
	}
	printf("合計呼び出し回数: %d\n", get_id()-1);
	return 0;

}
