// 下記のプログラムをベースとして，配列SrcDataと配列DstDataと配列SrcDataの要素数を引数として渡し，配
// 列SrcDataの配列SrcDataにコピーする “関数copy_func”を定義して，実際に動作させなさい．ただし， 関数
// copy_funcの引数の変数名は変えないこと

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