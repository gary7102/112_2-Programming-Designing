#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 21

int hasDuplicates(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] == arr[j]) {
                return 1;
            }
        }
    }
    return 0;
}

int compare(const void *a, const void *b) {
    const int *arr1 = *(const int **)a;
    const int *arr2 = *(const int **)b;
    for (int i = 0; i < MAX_LENGTH; i++) {
        if (arr1[i] < arr2[i]) return -1;
        if (arr1[i] > arr2[i]) return 1;
    }
    return 0;
}

// 新增函式來比較兩個子序列是否完全相同
int isSame(int *arr1, int *arr2, int len) {
    for (int i = 0; i < len; i++) {
        if (arr1[i] != arr2[i]) {
            return 0; // 不相同
        }
    }
    return 1; // 完全相同
}

// 新增函式來檢查子序列是否已存在於distinctSubsequences中
int alreadyExists(int **distinctSubsequences, int count, int *subseq, int m) {
    for (int i = 0; i < count; i++) {
        if (isSame(distinctSubsequences[i], subseq, m)) {
            return 1; // 已存在
        }
    }
    return 0; // 不存
}

int main() {
    int m, n;
    int sequence[MAX_LENGTH];
    int *distinctSubsequences[MAX_LENGTH * MAX_LENGTH] = {0};
    int count = 0;

    scanf("%d", &m);
    for (n = 0; n < MAX_LENGTH && scanf("%d", &sequence[n]) && sequence[n] != -1; n++);

    int repeat=0;
    for (int i = 0; i <= n - m; i++) {
        int subseq[m];
        for (int k = 0; k < m; k++) {
            subseq[k] = sequence[i + k];
        }
        if (!hasDuplicates(subseq, m)) {
            if(!alreadyExists(distinctSubsequences, count, subseq, m)){
                distinctSubsequences[count] = (int *)malloc(sizeof(int) * m);
                memcpy(distinctSubsequences[count], subseq, sizeof(int) * m);
                count++;
            }else{
                repeat++;
            }
        }
    }

    qsort(distinctSubsequences, count, sizeof(int *), compare);

    repeat += count;
    printf("%d\n", repeat);
    
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", distinctSubsequences[i][j]);
        }
        printf("\n");
        free(distinctSubsequences[i]);
    }

    return 0;
}
