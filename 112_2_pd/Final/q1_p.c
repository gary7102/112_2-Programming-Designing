#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

typedef struct{
    char *word;
    int count;
} WordEntry;

void insertQwithP(char *article[], char p[], char q[], int totalWords){
    for(int i=0; i<totalWords; i++){
        if(strcmp(article[i], p) == 0) printf("%s ", q);
        printf("%s ", article[i]);
    }
}

void replacePwithQ(char *article[], char p[], char q[], int totalWords){
    for(int i=0; i<totalWords; i++){
        if(strcmp(article[i], p) == 0) printf("%s ", q);
        else printf("%s ", article[i]);
    }
}

void deleteP(char *article[], char p[], int totalWords){
    for(int i=0; i<totalWords; i++){
        if(strcmp(article[i], p) != 0) printf("%s ", article[i]);
    }
}

void removeLowFrequency(char *article[], int totalWords, int n){
    WordEntry entries[MAX_LEN] = {0};
    int uniqueWords = 0;
    for(int i=0; i<totalWords; i++){
        int found = 0;
        for(int j=0; j<uniqueWords; j++){
            if(strcmp(article[i], entries[j].word) == 0){
                entries[j].count++;
                found = 1;
                break;
            }
        }
        if(!found){
            entries[uniqueWords].count++;
            entries[uniqueWords].word = article[i];
            uniqueWords++;
        }
    }
    for(int i=0; i<totalWords; i++){
        for(int j=0; j<uniqueWords; j++){
            if((strcmp(article[i], entries[j].word) == 0) && entries[j].count >=3){
            printf("%s ", article[i]);
            break;
            }
        }
    }
}

int compare(const void *a, const void *b){
    WordEntry *word1 = (WordEntry*)a;
    WordEntry *word2 = (WordEntry*)b;
    if(word1->count != word2->count) return word1->count - word2->count; //升序
    else return strcmp(word1->word, word2->word);   //字典升序
}

void outputFrequency(char *article[], int totalWords){
    WordEntry entries[MAX_LEN] = {0};
    int uniqueWords = 0;
    for(int i=0; i<totalWords; i++){
        int found = 0;
        for(int j=0; j<uniqueWords; j++){
            if(strcmp(article[i], entries[j].word) == 0){
                entries[j].count++;
                found = 1;
                break;
            }
        }
        if(!found){
            entries[uniqueWords].count++;
            entries[uniqueWords].word = article[i];
            uniqueWords++;
        }
    }
    qsort(entries, uniqueWords, sizeof(WordEntry), compare);

    int count = (uniqueWords < 3)? uniqueWords : 3;
    for(int i=0; i<count; i++){ 
        printf("%s:%d\n", entries[i].word, entries[i].count);
    }

}

void main(){
    char article[MAX_LEN], p[100], q[100];
    int c, n = 0;

    fgets(article, sizeof(article), stdin);
    article[strcspn(article, "\n")] = 0;

    scanf("%s", p);
    scanf("%s", q);
    scanf("%d", &c);
    if(c == 4) scanf("%d", &n);

    // tokenize the article
    char *arr[MAX_LEN];
    int totalWords = 0;
    char *token = strtok(article, " ");
    while(token != NULL){
        arr[totalWords++] = token;
        token = strtok(NULL, " ");
    }

    if(c == 1){
        insertQwithP(arr, p, q, totalWords);
    }
    else if(c == 2){
        replacePwithQ(arr, p, q, totalWords);
    }
    else if(c == 3){
        deleteP(arr, p, totalWords);
    }
    else if(c == 4){
        removeLowFrequency(arr, totalWords, n);
    }else if(c == 5){
        outputFrequency(arr, totalWords);
    }
}