#include<stdio.h>
#include<string.h> // strlen

int main(){
    printf("=== 文字列解析プログラム ===\n文字列を入力してください:");
    char str[100];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("入力された文字列:");
    int i =0;
    while(str[i] != '\0'){
        printf("%c",str[i]);
        i++;
    }
    printf("\n");

    //解析
    i =0;
    int M=0,m=0,num=0,other=0;
    int str_len = (int)strlen(str); 
    while(str[i] !='\0'){
        char a = str[i];
        if(a >= 'a' && a<='z') m++;
        else if(a >= 'A' && a<='Z') M++;
        else if(a >='0' && a <= '9') num++;
        else other++;

        i++;
    }
    printf("---解析結果---\n");
    printf("文字列の長さ: %d\n",str_len); 
    printf("大文字の個数: %d\n",M);      
    printf("小文字の個数: %d\n",m);      
    printf("数字の個数: %d\n",num);      
    printf("その他の個数: %d\n",other);  
    // 逆
    printf("逆順文字列: ");
    for(i = str_len - 1; i >= 0; i--){
        printf("%c",str[i]); 
    }
    printf("\n");
    return 0;
}