#include <stdio.h>

int main(void) {
    // ここにコードを書いてください
    //
// 要件
// • int current_state, elapsed_time
//  • int state_duration, time_remaining
//  • switch文で状態判定（必須・3個のcase文 + default）
// 1: 青信号（30秒） → 黄信号へ
// 2: 黄信号（5秒） → 赤信号へ
// 3: 赤信号（25秒） → 青信号へ
// • if-else文で入力検証（必須）
// 状態: 1-3の範囲
// 経過時間: 0秒以上（負数を0にクランプ）
// ※クランプの意味- 値が最小値より小さい → 最小値を返す- 値が最大値より大きい → 最大値を返す- 値が範囲内 → その値をそのまま返す
// • if-else文で残り時間計算
// 残り時間= 継続時間-経過時間
// 0秒未満にならないように
// • 状態遷移メッセージ（重要！）
// 残り時間== 0秒→ "次の状態に切り替わります"
// 残り時間> 0秒→ "まだ継続します"
//  ⚠
// エラー処理（必須）
// • 入力検証を必ず実装してください
// • エラー時はエラーメッセージを表示して終了（return 1）
// • 検証項目:- 信号状態: 1-3以外 → エラー- 経過時間: 負数の場合は0にクランプ
    // 1. 現在の信号状態（1-3）を入力
    //    1: 青信号 (30秒間)
    //    2: 黄信号 (5秒間)
    //    3: 赤信号 (25秒間)
    // 2. 経過時間（秒）を入力
    //
    // switch文を使用して:
    // - 現在の状態を判定
    // - 各状態の継続時間を設定
    // - 次の状態を決定
    // - 状態遷移のルール:
    //   青信号(30秒) → 黄信号
    //   黄信号(5秒) → 赤信号
    //   赤信号(25秒) → 青信号
    //
    // if-else文を使用して:
    // - 入力値の検証（状態は1-3、経過時間は0以上）
    // - 残り時間の計算
    // - 状態遷移のタイミング判定
    //
    // 出力形式:
    // 現在の状態: [青信号/黄信号/赤信号]
    // 状態の継続時間: [X]秒
    // 次の状態: [青信号/黄信号/赤信号]
    // 残り時間: [X]秒
    // 状態遷移: [メッセージ]
    //
    // 計算例:
    // 入力: 状態1(青信号), 経過時間15秒
    // 出力:
    //   現在の状態: 青信号
    //   状態の継続時間: 30秒
    //   次の状態: 黄信号
    //   残り時間: 15秒
    //   状態遷移: まだ青信号が継続します
    //
    // 入力: 状態1(青信号), 経過時間30秒
    // 出力:
    //   現在の状態: 青信号
    //   状態の継続時間: 30秒
    //   次の状態: 黄信号
    //   残り時間: 0秒
    //   状態遷移: 黄信号に切り替わります

//     実行例（正常ケース）:
// 現在の信号状態を入力してください(1-3): 1
// 経過時間を入力してください(秒): 25
// 現在の状態: 青信号
// 状態の継続時間: 30秒
// 次の状態: 黄信号
// 残り時間: 5秒
// 状態遷移: まだ青信号が継続します
// ─────────────────────
// 現在の信号状態を入力してください(1-3): 2
// 経過時間を入力してください(秒): 5
// 現在の状態: 黄信号
// 状態の継続時間: 5秒
// 次の状態: 赤信号
// 残り時間: 0秒
// 状態遷移: 赤信号に切り替わります
// ─────────────────────
// サイクル時間: 60秒（30+5+25）
// 青→ 黄→ 赤→ 青（繰り返し）
// 実行例（エラーケース）:
// 現在の信号状態を入力してください(1-3): 0
// エラー: 信号状態は1-3の範囲で入力してください
// ─────────────────────
// 現在の信号状態を入力してください(1-3): 4
// エラー: 信号状態は1-3の範囲で入力してください

    int current_state, elapsed_time;
    int state_duration = 0, time_remaining = 0;

    // 入力
    printf("現在の信号状態を入力してください(1-3): ");
    scanf("%d", &current_state);
    if(current_state < 1 || current_state > 3) {
        printf("エラー: 信号状態は1-3の範囲で入力してください\n");
        return 1;
    }
    printf("経過時間を入力してください(秒): ");
    scanf("%d", &elapsed_time);
    if(elapsed_time < 0) {
        elapsed_time = 0; 
        return 1;
    }
    // 状態判定と継続時間設定
    if(current_state == 1) {
        state_duration = 30;
    } else if(current_state == 2) {
        state_duration = 5;
    } else if(current_state == 3) {
        state_duration = 25;
    }
    // 残り時間計算
    time_remaining = state_duration - elapsed_time;
    if(time_remaining < 0) {
        time_remaining = 0;
    }
    // 出力
    printf("現在の状態: ");
    switch(current_state) {
        case 1:
            printf("青信号\n");
            break;
        case 2:
            printf("黄信号\n");
            break;
        case 3:
            printf("赤信号\n");
            break;
        default:
            break;
    }
    printf("状態の継続時間: %d秒\n", state_duration);
    printf("次の状態: ");
    switch(current_state) {
        case 1:
            printf("黄信号\n");
            break;
        case 2:
            printf("赤信号\n");
            break;
        case 3:
            printf("青信号\n");
            break;
        default:
            break;
    }
    printf("残り時間: %d秒\n", time_remaining);
    printf("状態遷移: ");
    if(time_remaining == 0) {
        switch(current_state) {
            case 1:
                printf("黄信号に切り替わります\n");
                break;
            case 2:
                printf("赤信号に切り替わります\n");
                break;
            case 3:
                printf("青信号に切り替わります\n");
                break;
            default:
                break;
        }
    } else {
        switch(current_state) {
            case 1:
                printf("まだ青信号が継続します\n");
                break;
            case 2:
                printf("まだ黄信号が継続します\n");
                break;
            case 3:
                printf("まだ赤信号が継続します\n");
                break;
            default:
                break;
        }
    }   



    return 0;
}