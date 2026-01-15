#include <stdio.h>

double calc_min(double a[]){
	double min = a[0];
	for(int i=1;i<20;i++){
		if(min>a[i]) min=a[i];
	}
	return min;
}
int main(){
	double A[] = { 92.0 ,-36.5 ,48.8 ,49.6 ,-24.2 , 54.1 ,20.8 ,-31.5 ,-59.5 ,-94.5, -97.0 , -8.8 ,79.3 ,64.6 , 5.1 ,-40.5 ,20.2 ,-95.9 ,-34.9 ,78.1};
	printf("最小値＝%.2lf\n",calc_min(A));
}
