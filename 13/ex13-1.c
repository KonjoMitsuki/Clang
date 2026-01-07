//  下記のプログラムは，画面上に“関数test_func”に配列と要素数を引数として渡し，その配列の合計値を戻り
// 値として返すの関数と それを表示するプログラムである．プログラムの動作を予想し，確認をしなさい．
// さらに, その配列の合計値ではなく，平均値を実数で戻り値として返す関数に改修して，動作させなさい．

#include <stdio.h>

int test_func(int data[], int data_size){
    int i,sum = 0;
    for(i = 0; i < data_size; i++)
        sum += data[i];

    return sum;
}

int main(){
    int Data[8] = {2,4,5,7,8,9,11,15};
    int val;

    val = test_func(Data, 8);

    printf("test_funcの戻り値は %d です\n", val);
    return 0;
}