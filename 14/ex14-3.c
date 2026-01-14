#include<stdio.h>
#define DatNum 8

int Rev_Func2(int x[]){
    int temp;
    for(int i = 0; i < 5/2; i++){
        temp = x[i];
        x[i] = x[4-i];
        x[4-i] = temp;
    }
    return 0;
}
int main(){
    int SrcDat[DatNum] = {2,4,5,7,8,9,11,15};
    int i;
    Rev_Func2(SrcDat);
    for(int i = 0; i < DatNum; i++)
        printf("SrcDat[%d]=%d\n",i,SrcDat[i]);

    return 0;
}