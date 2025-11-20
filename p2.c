#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   

int main()
{
    int target_number, guess, attempts;

    // ランダム数の初期化と生成
    srand((unsigned int)time(0));
    target_number = rand() % 100 + 1;  // 1-100のランダムな数

    attempts = 0;

    printf("=== 数字当てゲーム ===\n");
    printf("1から100までの数字を当ててください\n\n");

    // TODO: while文を使ってゲームのロジックを実装してください
    // ヒント: while (guess != target_number) { ... }

    while(guess != target_number){
        printf("推測 %d回目: ", attempts);
        scanf("%d", &guess);
        if(guess < 1 || guess > 100){
            printf("エラー: 1-100の範囲で入力してください\n");
        }else{
            attempts++;
            if(guess < target_number)
                printf("もっと大きい数字です\n");
            else if(guess > target_number)
                printf("もっと小さい数字です");
            else
                printf("正解です!");
        }      
    }
    printf("試行回数: %d\n", attempts);

}