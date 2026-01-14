#include<stdio.h>

void Rev_Func(int s[], int d[]){
    for(int i = 0; i < 5; i++){
        d[i] = s[4 - i];
    }
}
int main(){
    int SrcDat[5] = {2,4,5,7,8,11,15};
    int DstDat[5];
    Rev_Func(SrcDat,DstDat);
    for(int i = 0; i < 5; i++)
        printf("SrcDat[%d]=%d \t, DstDat[%d]=%d\n",i,SrcDat[i],i,DstDat[i]);
    
    return 0;
}