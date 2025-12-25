#include<stdio.h>

int find_max(int arr[], int size);
int find_min(int arr[], int size);
double calc_average(int arr[], int size);

int main(){
    int size;
    printf("配列のサイズを入力してください\n");
    scanf("%d",&size);
    if(size < 1 || size > 10){
        printf("エラー: サイズは1以上10以下で入力してください\n");
        return 1;
    }
    int a[size];
    for(int i=0;i<size;i++){
        printf("要素[%d]を入力: ",i);
        scanf("%d",&a[i]);
    }
    printf("最大値: %d",(int)find_max(a,size));
    printf("最小値: %d",(int)find_min(a,size));
    printf("平均値: %d",(int)calc_average(a,size));

    return 0;
}

int find_max(int arr[], int size){
    int max = arr[0];
    for(int i= 1;i<size;i++){
        if(arr[i] > max ){max  = arr[i];}
    }
    return max;

}

int find_min(int arr[], int size){
    int min = arr[0];
    for(int i= 1;i<size;i++){
        if(arr[i] < min ){min  = arr[i];}
    }
    return min;
}

double calc_average(int arr[], int size){
    int sum = arr[0];
    for(int i= 1;i<size;i++)
        sum  += arr[i];
    return sum/size;

}