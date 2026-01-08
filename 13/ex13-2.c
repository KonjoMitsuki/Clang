#include <stdio.h>

void copfunc(int S[], int D[], int data_size){
    for(int i = 0; i < data_size; i++){
        D[i] = S[i];
    }
}

int main(){
    int SrcData[8] = {2,4,5,7,8,9,11,15};
    int DstData[8] = {0,0,0,0,0,0,0,0};
    int i;

    copfunc(SrcData, DstData, 8);

    for(i = 0; i < 8; i++){
        printf("SrcData[%d] = %d, DstData[%d] = %d\n", i, SrcData[i], i, DstData[i]);
    }

    return 0;
}