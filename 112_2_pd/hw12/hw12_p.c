#include <stdio.h>
#include <string.h>

int getActionCode(const char *action) {
    if (strcmp(action, "1B") == 0) return 1;
    if (strcmp(action, "2B") == 0) return 2;
    if (strcmp(action, "3B") == 0) return 3;
    if (strcmp(action, "HR") == 0) return 4;
    if (strcmp(action, "FO") == 0) return 5;
    if (strcmp(action, "GO") == 0) return 5;
    if (strcmp(action, "SO") == 0) return 5;
    return 0;
}

void advanceBases(int *bases, int hit) {
    if (hit == 4) { // Home run
        for (int i = 0; i < 3; ++i) {
            bases[i] = 1; // Each runner will score
        }
    } else {
        for (int i = 2; i >= hit; --i) {
            bases[i] = bases[i - hit]; // Advance runners
        }
        for (int i = hit - 1; i >= 0; --i) {
            bases[i] = 0; // Empty the passed bases
        }
        bases[hit - 1] = 1; // Place hitter on base
    }
}

void scoreRuns(int *bases, int *score) {
    for (int i = 2; i >= 0; --i) {
        if (bases[i]) {
            *score += 1;
        }
        bases[i] = 0; // Clear the bases after scoring
    }
}

int main() {
    int playerActions[9][27]; // Up to 27 actions per player, as 27 outs are possible in a game
    int actionCounts[9] = {0};
    int bases[3] = {0};
    int score = 0;
    int outCount = 0;
    int b, totalOuts;

    for (int i = 0; i < 9; ++i) {
        scanf("%d", &actionCounts[i]);
        for (int j = 0; j < actionCounts[i]; ++j) {
            char action[3];
            scanf("%s", action);
            playerActions[i][j] = getActionCode(action);
        }
    }
    scanf("%d", &totalOuts);

    for (int i = 0, player = 0; outCount < totalOuts; player = (player + 1) % 9) {
        int actionCode = playerActions[player][i];
        if (actionCode == 5) { // Out
            outCount++;
            if (outCount % 3 == 0) { // Inning over, clear bases
                bases[0] = bases[1] = bases[2] = 0;
            }
        } else {
            advanceBases(bases, actionCode);
            if (actionCode == 4) { // Home run, score all and clear bases
                scoreRuns(bases, &score);
                score++; // Add score for the hitter
            }
        }
        i++;
        if (i >= actionCounts[player]) {
            i = 0; // Next player's turn
        }
    }

    // Score any remaining runners on base
    scoreRuns(bases, &score);

    printf("%d\n", score);
    return 0;
}
