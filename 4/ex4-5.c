#include<stdio.h>
#include<math.h>

int main(){
    int R1 = 0, R2 = 0, Rs = 0;

    printf("整数で抵抗R1の抵抗値を入力してください\n");
    scanf("%d", &R1);

    printf("整数で抵抗R2の抵抗値を入力してください\n");
    scanf("%d",&R2);

    Rs = round((double)R1 * (double)R2 / ((double)R1 + (double)R2));

    printf("R1=%dΩ, R2=%dΩのとき　並列合成抵抗Rs=%dΩ\n",R1,R2,Rs);
    getchar();
    return 0;
} 