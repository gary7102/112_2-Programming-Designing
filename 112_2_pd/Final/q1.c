// 文章處理 hw20
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000
#define MAX_WORDS 100

typedef struct {
    char *word;
    int count;
} WordEntry;

void insertQBeforeP(char *article[], char p[], char q[], int totalWords) {
    int newWords = 0;
    char *newArticle[MAX_WORDS];

    for (int i = 0; i < totalWords; i++) {
        if (strcmp(article[i], p) == 0) {
            newArticle[newWords++] = q;
        }
        newArticle[newWords++] = article[i];
    }

    for (int i = 0; i < newWords; i++) {
        printf("%s ", newArticle[i]);
    }
    printf("\n");
}

void replacePwithQ(char *article[], char p[], char q[], int totalWords) {
    for (int i = 0; i < totalWords; i++) {
        if (strcmp(article[i], p) == 0) {
            article[i] = q;
        }
    }

    for (int i = 0; i < totalWords; i++) {
        printf("%s ", article[i]);
    }
    printf("\n");
}

void deleteP(char *article[], char p[], int totalWords) {
    for (int i = 0; i < totalWords; i++) {
        if (strcmp(article[i], p) != 0) {
            printf("%s ", article[i]);
        }
    }
    printf("\n");
}

void removeLowFrequencyWords(char *article[], int totalWords, int n) {
    WordEntry entries[MAX_WORDS] = {0};
    int uniqueWords = 0;

    for (int i = 0; i < totalWords; i++) {
        int found = 0;
        for (int j = 0; j < uniqueWords; j++) {
            if (strcmp(entries[j].word, article[i]) == 0) {
                entries[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            entries[uniqueWords].word = article[i];
            entries[uniqueWords].count = 1;
            uniqueWords++;
        }
    }

    for (int i = 0; i < totalWords; i++) {
        for (int j = 0; j < uniqueWords; j++) {
            if (strcmp(article[i], entries[j].word) == 0 && entries[j].count >= n) {
                printf("%s ", article[i]);
                break;
            }
        }
    }
    printf("\n");
}

int compare(const void *a, const void *b) {
    WordEntry *word1 = (WordEntry *)a;
    WordEntry *word2 = (WordEntry *)b;
    if (word1->count != word2->count) {
        return word1->count - word2->count;  // 升序
    } else {    
        return strcmp(word1->word, word2->word);  // 字典升序
    }
}

void outputfrequency(char *article[], int totalWords) {
    WordEntry entries[MAX_WORDS] = {0};
    int uniqueWords = 0;

    for (int i = 0; i < totalWords; i++) {
        int found = 0;
        for (int j = 0; j < uniqueWords; j++) {
            if (strcmp(entries[j].word, article[i]) == 0) {
                entries[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            entries[uniqueWords].word = article[i];
            entries[uniqueWords].count = 1;
            uniqueWords++;
        }
    }

    qsort(entries, uniqueWords, sizeof(WordEntry), compare);

    for (int i = 0; i < (uniqueWords < 3 ? uniqueWords : 3); i++) {
        printf("%s:%d\n", entries[i].word, entries[i].count);
    }
}

int main() {
    char p[200], q[200], article[MAX_LEN];
    int C, N = 0;

    // Read input
    fgets(article, sizeof(article), stdin);
    article[strcspn(article, "\n")] = 0;  // Remove newline character

    scanf("%s", p);
    scanf("%s", q);
    scanf("%d", &C);
    if (C == 4) {
        scanf("%d", &N);
    }

    // Tokenize the article
    char *arr[MAX_WORDS];
    int totalWords = 0;
    char *token = strtok(article, " ");
    while (token != NULL) {
        arr[totalWords++] = token;
        token = strtok(NULL, " ");
    }

    // Process based on command C
    switch (C) {
        case 1:
            insertQBeforeP(arr, p, q, totalWords);
            break;
        case 2:
            replacePwithQ(arr, p, q, totalWords);
            break;
        case 3:
            deleteP(arr, p, totalWords);
            break;
        case 4:
            removeLowFrequencyWords(arr, totalWords, N);
            break;
        case 5:
            outputfrequency(arr, totalWords);
            break;
        default:
            printf("Invalid command\n");
    }

    return 0;
}
