#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int order; // 球員順序
    int hits;  // 安打數
    int runs;  // 總跑壘數
} Player;

int compare(const void *a, const void *b) {
    Player *player1 = (Player *)a;
    Player *player2 = (Player *)b;
    if (player1->runs == player2->runs) return player1->order - player2->order;
    return player2->runs - player1->runs;
}

void updateBasesAndScore(char hit, int bases[4], int *score, Player *player, Player players[9], int current_player) {
    int advance = 0; // 前進的壘數
    if (hit == 'H') advance = 4;
    else if (hit == 'O') advance = 0;
    else advance = hit - '0';
    
    // current_player+=1;
    // 更新跑壘
    if (advance > 0) {
        for (int i = 3; i >= 0; --i) {
            if (bases[i]) {
                if (i + advance >= 4) {
                    players[bases[i]-1].runs += (4-i);
                    (*score)++;
                } else {
                    bases[i + advance] = bases[i];
                    players[bases[i]-1].runs += advance;
                }
                bases[i] = 0; // 清空原有位置1
            }
        }

        if (advance < 4){
            bases[advance] = current_player+1; // 打者上壘
            // printf("base[%d] = %d\n", advance, current_player);
        }else{
            (*score)++; // 全壘打
        }
        player->runs += advance; // 更新跑壘數

        // printf("advance = %d\n", advance);
        // // printf("current_player[%d] : runs = %d\n", current_player, players[current_player].runs);
        // printf("bases = %d %d %d\n", bases[1], bases[2], bases[3]);
        
    }
}

int main() {
    Player players[9];
    char hits[9][5]; // 最多5次打擊
    int bases[4] = {0}; // 壘包狀態
    int N, score = 0;
    int hitCounts[9] = {0}; // 紀錄每位球員的打擊次數

    for (int i = 0; i < 9; i++) {
        players[i].order = i + 1;
        players[i].hits = 0;
        players[i].runs = 0;
        scanf("%d", &hitCounts[i]);
        for (int j = 0; j < hitCounts[i]; j++) {
            scanf(" %c", &hits[i][j]);
        }
    }
    scanf("%d", &N); // 指定出局數

    int outs = 0, playerIndex = 0;
    while (outs < N) {
        for (int i = 0; i < 9 && outs < N; i++) { // 按球員順序輪流打擊
            if (playerIndex < hitCounts[i]) {
                char hit = hits[i][playerIndex];
                if (hit == 'O') {
                    outs++;
                    if (outs % 3 == 0) {
                        for (int j = 0; j < 4; j++) bases[j] = 0; // 三出局清空壘包
                    }
                } else {
                    players[i].hits++;
                    updateBasesAndScore(hit, bases, &score, &players[i], players, i);
                }
            }
        }
        playerIndex++; // 移動到下一輪打擊
    }
    
    // 排序球員
    qsort(players, 9, sizeof(Player), compare);

    // 輸出結果
    printf("%d\n", score); // 總得分
    for (int i = 0; i < 3; i++) {
        printf("%d %d %d\n", players[i].order, players[i].hits, players[i].runs);
    }
    return 0;
}