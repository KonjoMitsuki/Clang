#include <stdio.h>

int have = 1000;

int import_account(int nyuukinn) {
    static int count = 0; 

    if (nyuukinn < 1 || nyuukinn > 10000) {
        printf("エラー: 1以上10000以下の数値を入力してください\n");
        return have; 
    }

    have += nyuukinn;
    count++;
    printf("入金完了（取引#%d）残高: %d\n", count, have);
    return have;
}

int export_account(int shukkin) {
    static int count = 0;

    if (shukkin < 1 || shukkin > 10000) {
        printf("エラー: 1以上10000以下の数値を入力してください\n");
        return have;
    }

    if (have < shukkin) {
        printf("エラー: 残高不足\n");
        return have;
    }

    have -= shukkin;
    count++;
    printf("出金完了（取引#%d）残高: %d\n", count, have);
    return have;
}

int main() {
    int money; 

    printf("=== 銀行口座シミュレーション ===\n");
    printf("初期残高: %d", have); 
    
    printf("--- 入金 ---\n");
    
    printf("入金額を入力してください: ");
    scanf("%d", &money);
    import_account(money);

    printf("入金額を入力してください: ");
    scanf("%d", &money);
    import_account(money);

    printf("--- 出金 ---\n");

    printf("出金額を入力してください: "); 
    scanf("%d", &money);
    export_account(money);

    printf("出金額を入力してください: ");
    scanf("%d", &money);
    export_account(money);

    printf("最終残高: %d\n", have);

    return 0;
}
