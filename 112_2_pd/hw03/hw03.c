/*
003. 棒球壘包

根據棒球隊球員打擊結果，計算出球隊的得分。

棒球規則如下：
球場上有四個壘包， 稱為本壘、一、二和三壘。
本壘握球棒打的稱「擊球員」 ，在另外三個壘包的稱為「跑員」。
當擊球員打擊「安打」時， 擊球員與跑壘員可移動，
「出局」時，跑壘員不動，擊球員離場換下一位。

擊球員打擊情況如下：
安打：以1, 2, 3 和 4 代表一、二、三和全(四)壘打。
出局：以 0 表示出局。

比賽開始由第 1位打擊，接著2, 3, 4, 5位球員。
打出 K 壘打時，場上球員(擊球員和跑壘員)會前進 K個壘包。
本壘到一壘，接著二、三壘，最後回到本壘。回到本壘可得1分。
每達到三個出局數時，壘包清空(跑壘員都得離開)，重新開始。

最後根據5位擊球員打擊情況，計算出球隊得分與一、二、三壘的情況，有人為1，沒人為0。

【輸入說明】
第一行：輸入一個字元，代表打者1擊出的安打數
第二行：輸入一個字元，代表打者2擊出的安打數
第三行：輸入一個字元，代表打者3擊出的安打數
第四行：輸入一個字元，代表打者4擊出的安打數
第五行：輸入一個字元，代表打者5擊出的安打數

範例輸入說明:
1 (打者1擊出1壘安打)
2 (打者2擊出2壘安打)
3 (打者3擊出3壘安打)
4 (打者4擊出全壘打)
0 (打者5出局)

【輸出說明】
第一行輸出球隊總得分 (總得分為整數)
第二行分別輸出一壘、二壘、三壘的情況，中間以空白隔開，壘包上有人為1，壘包上沒人為0。

範例輸出說明:
4 (總得分為4分)
0 0 0 (分別代表一壘沒人、二壘沒人、三壘沒人，中間以空白隔開)

【測試資料一】
輸入：
1
2
3
4
4

輸出：
5
0 0 0

【測試資料二】
輸入：
1
0
0
0
4

輸出：
1
0 0 0

【測試資料三】
輸入：
2
1
0
0
1

輸出：
1
1 1 0

【測試資料四】
輸入：
0
1
0
2
0

輸出：
0
0 0 0
*/


#include <stdio.h>

int calculate_score(int state, int score){
    state = state>>3;

    if(state&1){
        score++;
    }
    state = state>>1;
    if(state&1){
        score++;
    }
    state = state>>1;
    if(state&1){
        score++;
    }
    state = state>>1;
    if(state&1){
        score++;
    }
    return score;
}

int main() {
    int state=0, input=0, score=0, zero_count = 0;

    scanf("%d", &input);
    if(!input) zero_count++;
    state = (state <<input) | (1<<(input-1));
    
    if(state>7){
        score = calculate_score(state, score);
    }
    state = state&7;

    scanf("%d", &input);
    if(!input) zero_count++;
    state = (state <<input) | (1<<(input-1));
    if(state>7){
        score = calculate_score(state, score);
    }
    state = state&7;

    scanf("%d", &input);
    if(!input) zero_count++;
    state = (state <<input) | (1<<(input-1));
    if(zero_count == 3) {
        state = 0;
        zero_count = 0;
    }
    if(state>7){
        score = calculate_score(state, score);
    }
    state = state&7;

    scanf("%d", &input);
    if(!input) zero_count++;
    state = (state <<input) | (1<<(input-1));
    if(zero_count == 3) {
        state = 0;
        zero_count = 0;
    }
    if(state>7){
        score = calculate_score(state, score);
    }
    state = state&7;

    scanf("%d", &input);
    if(!input) zero_count++;
    state = (state <<input) | (1<<(input-1));
    if(zero_count == 3) {
        state = 0;
        zero_count = 0;
    }
    if(state>7){
        score = calculate_score(state, score);
    }
    state = state&7;

    printf("%d\n", score);
    printf("%d %d %d\n", state&1, (state>>1)&1, (state>>2)&1);
    
    return 0;
}