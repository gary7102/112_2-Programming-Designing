#include <stdio.h>

int main() {
    int course1_id, course2_id, course3_id;
    int course1_hour, course2_hour, course3_hour;
    int course1_schedule[3], course2_schedule[3], course3_schedule[3];

    // 讀取第一堂課程的資料
    scanf("%d", &course1_id);
    scanf("%d", &course1_hour);
    for (int i = 0; i < course1_hour; i++) {
        scanf("%d", &course1_schedule[i]);
    }

    // 讀取第二堂課程的資料
    scanf("%d", &course2_id);
    scanf("%d", &course2_hour);
    for (int i = 0; i < course2_hour; i++) {
        scanf("%d", &course2_schedule[i]);
    }

    // 讀取第三堂課程的資料
    scanf("%d", &course3_id);
    scanf("%d", &course3_hour);
    for (int i = 0; i < course3_hour; i++) {
        scanf("%d", &course3_schedule[i]);
    }

    // 檢查課程是否衝堂
    int conflict = 0;
    for (int i = 0; i < course1_hour; i++) {
        for (int j = 0; j < course2_hour; j++) {
            if (course1_schedule[i] == course2_schedule[j]) {
                printf("%d,%d,%d\n", course1_id, course2_id, course1_schedule[i]);
                conflict = 1;
            }
        }
    }

    for (int i = 0; i < course1_hour; i++) {
        for (int j = 0; j < course3_hour; j++) {
            if (course1_schedule[i] == course3_schedule[j]) {
                printf("%d,%d,%d\n", course1_id, course3_id, course1_schedule[i]);
                conflict = 1;
            }
        }
    }

    for (int i = 0; i < course2_hour; i++) {
        for (int j = 0; j < course3_hour; j++) {
            if (course2_schedule[i] == course3_schedule[j]) {
                printf("%d,%d,%d\n", course2_id, course3_id, course2_schedule[i]);
                conflict = 1;
            }
        }
    }

    if (conflict == 0) {
        printf("correct\n");
    }

    return 0;
}
