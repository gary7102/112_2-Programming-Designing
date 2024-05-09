#include <stdio.h>
#include <string.h>

typedef struct student_s{
    char name[50];
    int score;
} student_t;

void input(student_t s[], int n){
    for(int i=0; i<n; i++){
        scanf("%s", s[i].name);
        scanf("%d", &s[i].score);
    }
}

void getHigh(student_t s[], int n, char name[]){
    int highestScore = s[0].score;
    strcpy(name, s[0].name);
    for (int i = 1; i < n; i++) {
        if (s[i].score > highestScore) {
            highestScore = s[i].score;
            strcpy(name, s[i].name);
        }
    }
}

int getAverage(student_t s[], int n){
    int sum = 0;
    for(int i=0; i<n; i++) sum+= s[i].score;
    return sum/n;
}

void main(){
    int N;
    scanf("%d", &N);
    student_t student[N];

    input(student, N);
    
    char highScoreName[50];
    getHigh(student, N, highScoreName);
    printf("%s\n", highScoreName);

    int avg = getAverage(student, N);
    printf("%d", avg);

}