#include<stdio.h>
int c = 10;
int func(int a,int b){
    // 6,1,10
    printf("5.a=%d b=%d c=%d\n",a,b,c);
    a *= 3;
    b *= 3;
    c *= 3;
    // 18,3,30
    printf("6.a=%d b=%d c=%d\n",a,b,c);
    return b+c;
}

int main(){
    int a =1,b = 5;
    // 1,5,10
    printf("1.a=%d b=%d c=%d\n",a,b,c);
    {
        int a = 2;
        // 2,5,10
        printf("2.a=%d b=%d c=%d\n",a,b,c);
        ++a;
        ++b;
        // 3,6,10
        printf("3.a=%d b=%d c=%d\n",a,b,c);
    }
    // 1,6,10
    printf("4.a=%d b=%d c=%d\n",a,b,c);
    a=func(b,a);
    // 18,6,30
    printf("7.a=%d b=%d c=%d\n",a,b,c);
    return 0;
}
