#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum scoreType_s { G, GPA, S } scoreType_t;
typedef enum G_s { Aplus, A, Aduce, Bplus, B, Bduce, Cplus, C, Cduce, F, X}G_t;
typedef enum GPA_s { b4dot3, b4dot0, b3dot7, b3dot3, b3dot0, b2dot7, b2dot3, b2dot0, b1dot7, b1, b0 } GPA_t;
typedef enum S_s { b90to100, b85to89, b80to84, b77to79, b73to76, b70to72, b67to69, b63to66, b60to62, b1to59, b0to0 } S_t;

// Mapping enums to scores based on the grading table provided
int letterToScore[] = {95, 87, 82, 78, 75, 70, 68, 65, 60, 50, 0}; // A+, A, B+, B, B-, etc.
int gpaToScore[] =    {95, 87, 82, 78, 75, 70, 68, 65, 60, 50, 0}; // 4.3, 4.0, 3.7, etc.
int rangeToScore[] =  {95, 87, 82, 78, 75, 70, 68, 65, 60, 50, 0}; // Assuming GPA range matches letter grades

typedef struct {
    int id;
    int average;
} studentAverage_t;

int compare(const void* a, const void* b) {
    studentAverage_t* studentA = (studentAverage_t*)a;
    studentAverage_t* studentB = (studentAverage_t*)b;
    return studentA->average - studentB->average;
}

int main() {
    int M, N;
    scanf("%d", &M);

    scoreType_t gradingTypes[M];
    char gradingType[4];
    for (int i = 0; i < M; i++) {
        scanf("%s", gradingType);
        if (strcmp(gradingType, "G") == 0) gradingTypes[i] = G;
        else if (strcmp(gradingType, "GPA") == 0) gradingTypes[i] = GPA;
        else if (strcmp(gradingType, "S") == 0) gradingTypes[i] = S;
    }

    scanf("%d", &N);
    studentAverage_t students[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &students[i].id);
        int totalScore = 0;
        char grade[10];

        for (int j = 0; j < M; j++) {
            scanf("%s", grade);
            int index = 0;

            switch (gradingTypes[j]) {
                case G:
                    if (strcmp(grade, "A+") == 0) index = Aplus;
                    else if (strcmp(grade, "A") == 0) index = A;
                    else if (strcmp(grade, "A-") == 0) index = Aduce;
                    else if (strcmp(grade, "B+") == 0) index = Bplus;
                    else if (strcmp(grade, "B") == 0) index = B;
                    else if (strcmp(grade, "B-") == 0) index = Bduce;
                    else if (strcmp(grade, "C+") == 0) index = Cplus;
                    else if (strcmp(grade, "C") == 0) index = C;
                    else if (strcmp(grade, "C-") == 0) index = Cduce;
                    else if (strcmp(grade, "F") == 0) index = F;
                    else if (strcmp(grade, "X") == 0) index = X;
                    totalScore += letterToScore[index];
                    break;
                case GPA:
                    if (strcmp(grade, "4.3") == 0) index = b4dot3;
                    else if (strcmp(grade, "4.0") == 0) index = b4dot0;
                    else if (strcmp(grade, "3.7") == 0) index = b3dot7;
                    else if (strcmp(grade, "3.3") == 0) index = b3dot3;
                    else if (strcmp(grade, "3.0") == 0) index = b3dot0;
                    else if (strcmp(grade, "2.7") == 0) index = b2dot7;
                    else if (strcmp(grade, "2.3") == 0) index = b2dot3;
                    else if (strcmp(grade, "2.0") == 0) index = b2dot0;
                    else if (strcmp(grade, "1.7") == 0) index = b1dot7;
                    else if (strcmp(grade, "1") == 0) index = b1;
                    else if (strcmp(grade, "0") == 0) index = b0;
                    totalScore += gpaToScore[index];
                    break;
                case S:
                    if (strcmp(grade, "90-100") == 0) index = b90to100;
                    else if (strcmp(grade, "85-89") == 0) index = b85to89;
                    else if (strcmp(grade, "80-84") == 0) index = b80to84;
                    else if (strcmp(grade, "77-79") == 0) index = b77to79;
                    else if (strcmp(grade, "73-76") == 0) index = b73to76;
                    else if (strcmp(grade, "70-72") == 0) index = b70to72;
                    else if (strcmp(grade, "67-69") == 0) index = b67to69;
                    else if (strcmp(grade, "63-66") == 0) index = b63to66;
                    else if (strcmp(grade, "60-62") == 0) index = b60to62;
                    else if (strcmp(grade, "1-59") == 0) index = b1to59;
                    else if (strcmp(grade, "0") == 0) index = b0to0;
                    totalScore += rangeToScore[index];
                    break;
            }
        }
        students[i].average = totalScore / M;
    }

    qsort(students, N, sizeof(studentAverage_t), compare);

    for (int i = 0; i < N; i++) {
        printf("%d %d\n", students[i].id, students[i].average);
    }

    return 0;
}
