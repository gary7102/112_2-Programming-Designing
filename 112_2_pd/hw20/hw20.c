#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
This is a book That is a cook
is
was
*/

typedef struct {
    char *word;
    int count;
} WordEntry;

void replacePwithQ(char *article[], char p[], char q[], int totalWords){
    for (int i = 0; i < totalWords; i++){   
        if(strcmp(*(article+i), p) == 0){
            *(article+i) = q;
        }
    }

    for (int i = 0; i < totalWords; i++){   
        printf("%s ", *(article+i));
    }
    printf("\n");
}

void insertQBeforeP(char *article[], char p[], char q[], int totalWords){
    int countP=0;
    for (int i = 0; i < totalWords; i++){   
        if(strcmp(*(article+i), p) == 0) countP++;
    }

    char **newArticle = malloc(sizeof(char*) * (totalWords + countP));
    int j=0;
    for(int i=0; i<totalWords; i++){
        if(strcmp(*(article+i), p) == 0) newArticle[j++] = q;
        newArticle[j++] = article[i];
    }

    for (int i = 0; i < (totalWords+countP); i++) printf("%s ", newArticle[i]);
    printf("\n");

    free(newArticle);
}

void deleteP(char *article[], char p[], char q[], int totalWords){
    int countP=0;
    for (int i = 0; i < totalWords; i++){   
        if(strcmp(*(article+i), p) == 0) countP++;
    }

    char **newArticle = malloc(sizeof(char*) * (totalWords - countP));
    int j=0;
    for(int i=0; i<totalWords; i++){
        if(strcmp(*(article+i), p) == 0) continue;
        newArticle[j++] = article[i];
    }

    for (int i = 0; i < (totalWords-countP); i++) printf("%s ", newArticle[i]);
    printf("\n");

    free(newArticle);
}

int compare(const void *a, const void *b) {
    WordEntry *word1 = (WordEntry *)a;
    WordEntry *word2 = (WordEntry *)b;
    if (word1->count != word2->count) {
        return word2->count - word1->count;  // 降序
    } else {
        return strcmp(word1->word, word2->word);  // 字典升序
    }
}

void outputfrequency(char *article[], int totalWords){
    WordEntry *entries = (WordEntry *)malloc(sizeof(WordEntry) * totalWords);
    int uniqueWords = 0;
    int found;

    for (int i = 0; i < totalWords; i++) {
        found = 0;
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

    for (int i = 0; i < uniqueWords; i++) {
        printf("%s %d\n", entries[i].word, entries[i].count);
    }

    free(entries);
}

int main(){
    char p[200], q[200], article[1000];
    fgets(article, sizeof(article), stdin);
    article[strcspn(article, "\n")] = 0;
    scanf("%s", p);
    scanf("%s", q);
    
    char *delim = " ";
    char *pch;
    char *arr1[51], *arr2[51], *arr3[51], *arr4[51];
    int i=0;
    pch = strtok(article, delim);
    while (pch != NULL) {
        arr1[i] = pch;
        arr2[i] = pch;
        arr3[i] = pch;
        arr4[i] = pch;
        i++;
        pch = strtok(NULL, delim);
    }
    int totalWords = i; // Store the total number of words
    replacePwithQ(arr1, p, q, totalWords);
    insertQBeforeP(arr2, p, q, totalWords);
    deleteP(arr3, p, q, totalWords);
    outputfrequency(arr4, totalWords);
    return 0;
}
/*
This is a book That is a cook
is
was
*/