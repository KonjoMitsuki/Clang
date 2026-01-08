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