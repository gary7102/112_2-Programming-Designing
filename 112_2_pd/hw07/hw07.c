#include <stdio.h>

int main(){
    int GamesNumber;
    int TotalScore[3] = {0, 0, 0};
    
    int Wins[3] = {0, 0, 0};
    char team1, team2;
    int score1, score2;

    scanf("%d", &GamesNumber);
    getchar();

    for(int i=0; i<GamesNumber; i++){

        scanf(" %c %c", &team1, &team2);

        int RoundScore[3] = {0, 0, 0};

        for(int j=0; j<4; j++){
            scanf("%d %d", &score1, &score2);

            if(team1 == 'A'){
                RoundScore[0] += score1;
            }else if(team1 == 'B'){
                RoundScore[1] += score1;
            }else if(team1 == 'C'){
                RoundScore[2] += score1;
            }
            if(team2 == 'A'){
                RoundScore[0] += score2;
            }else if(team2 == 'B'){
                RoundScore[1] += score2;
            }else if(team2 == 'C'){
                RoundScore[2] += score2;
            }
        }
        
        if(RoundScore[0] == 0){
            if(RoundScore[1] > RoundScore[2]){
                Wins[1]++;
            }else{
                Wins[2]++;
            }
            
        }else if(RoundScore[1] == 0){
            if(RoundScore[0] > RoundScore[2]){
                Wins[0]++;
            }else{
                Wins[2]++;
            }
        }else if(RoundScore[2] == 0){
            if(RoundScore[0] > RoundScore[1]){
                Wins[0]++;
            }else{
                Wins[1]++;
            }
        }
        TotalScore[0] += RoundScore[0];
        TotalScore[1] += RoundScore[1];
        TotalScore[2] += RoundScore[2];
    }
    // printf("%d\n", Wins[0]);
    // printf("%d\n", Wins[1]);
    // printf("%d\n", Wins[2]);
    // printf("%d\n", TotalScore[0]);
    // printf("%d\n", TotalScore[1]);
    // printf("%d\n", TotalScore[2]);

    // if(Wins[0]>Wins[1]){
    //     if(Wins[0]>Wins[2]){
    //         printf("A\n");
    //         printf("%d", TotalScore[0]);
    //     }else{
    //         printf("C\n");
    //         printf("%d", TotalScore[2]);
    //     }
    // }else{
    //     printf("B\n");
    //     printf("%d", TotalScore[1]);
    // }
    if(Wins[0]>Wins[1] && Wins[0]>Wins[2]){
        printf("A\n");
        printf("%d", TotalScore[0]);
    }else if(Wins[1]>Wins[0] && Wins[1]>Wins[2]){
        printf("B\n");
        printf("%d", TotalScore[1]);
    }else if(Wins[2]>Wins[0] && Wins[2]>Wins[1]){
        printf("C\n");
        printf("%d", TotalScore[2]);
    }
}