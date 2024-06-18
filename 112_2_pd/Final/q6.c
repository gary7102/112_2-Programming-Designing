//LinkList開發專案 hw35
#include <stdio.h>
#include <stdlib.h>

#define MAX_DEPENDENCIES 30

typedef struct node_s {
    int id;
    int time;
    struct node_s* nexts[MAX_DEPENDENCIES];
    int nextCount;
    int earliestStart;
    int earliestFinish;
    struct node_s* next;
} task_t;

typedef task_t* pTask;

pTask createTask(int id, int time) {
    pTask newTask = (pTask)malloc(sizeof(task_t));
    newTask->id = id;
    newTask->time = time;
    newTask->nextCount = 0;
    newTask->earliestStart = 0;
    newTask->earliestFinish = 0;
    newTask->next = NULL;
    for (int i = 0; i < MAX_DEPENDENCIES; i++) {
        newTask->nexts[i] = NULL;
    }
    return newTask;
}

void addDependency(pTask task, pTask dependency) {
    task->nexts[task->nextCount++] = dependency;
}

pTask findTask(pTask head, int id) {
    while (head != NULL) {
        if (head->id == id) return head;
        head = head->next;
    }
    return NULL;
}

void calculateEarliestTimes(pTask head, int numTasks) {
    int* inDegree = (int*)calloc(numTasks + 1, sizeof(int));
    pTask current = head;
    while (current != NULL) {
        for (int i = 0; i < current->nextCount; i++) {
            inDegree[current->nexts[i]->id]++;
        }
        current = current->next;
    }

    int* queue = (int*)malloc((numTasks + 1) * sizeof(int));
    int front = 0, rear = 0;
    current = head;
    while (current != NULL) {
        if (inDegree[current->id] == 0) {
            queue[rear++] = current->id;
            current->earliestStart = 0;
            current->earliestFinish = current->time;
        }
        current = current->next;
    }

    while (front < rear) {
        int currentId = queue[front++];
        current = head;
        while (current != NULL && current->id != currentId) current = current->next;
        for (int i = 0; i < current->nextCount; i++) {
            pTask nextTask = current->nexts[i];
            inDegree[nextTask->id]--;
            if (inDegree[nextTask->id] == 0) {
                queue[rear++] = nextTask->id;
            }
            if (nextTask->earliestStart < current->earliestFinish) {
                nextTask->earliestStart = current->earliestFinish;
                nextTask->earliestFinish = nextTask->earliestStart + nextTask->time;
            }
        }
    }

    free(inDegree);
    free(queue);
}

void findLongestPath(pTask head, int numTasks, int* longestPath, int* longestPathLength) {
    int maxFinishTime = 0;
    pTask current = head;
    while (current != NULL) {
        if (current->earliestFinish > maxFinishTime) {
            maxFinishTime = current->earliestFinish;
        }
        current = current->next;
    }

    current = head;
    while (current != NULL) {
        if (current->earliestFinish == maxFinishTime) {
            break;
        }
        current = current->next;
    }

    int pathIndex = 0;
    while (current != NULL) {
        longestPath[pathIndex++] = current->id;
        pTask nextTask = NULL;
        for (int i = 0; i < current->nextCount; i++) {
            if (current->nexts[i]->earliestFinish == maxFinishTime) {
                nextTask = current->nexts[i];
                break;
            }
        }
        current = nextTask;
        if (current != NULL) {
            maxFinishTime -= current->time;
        }
    }

    *longestPathLength = pathIndex;
}

void printTasks(pTask head) {
    while (head != NULL) {
        printf("Task %d: time=%d, earliestFinish=%d\n", head->id, head->time, head->earliestFinish);
        head = head->next;
    }
}

int main() {
    int M;
    scanf("%d", &M);
    int N;
    scanf("%d", &N);

    pTask head = NULL, tail = NULL;
    for (int i = 1; i <= N; i++) {
        int T, K;
        scanf("%d %d", &T, &K);
        pTask newTask = createTask(i, T);
        if (head == NULL) {
            head = newTask;
            tail = newTask;
        } else {
            tail->next = newTask;
            tail = newTask;
        }
        for (int j = 0; j < K; j++) {
            int depId;
            scanf("%d", &depId);
            pTask depTask = findTask(head, depId);
            addDependency(depTask, newTask);
        }
    }

    calculateEarliestTimes(head, N);

    if (M == 1) {
        int maxFinishTime = 0;
        pTask current = head;
        while (current != NULL) {
            if (current->earliestFinish > maxFinishTime) {
                maxFinishTime = current->earliestFinish;
            }
            current = current->next;
        }
        printf("%d\n", maxFinishTime);
    } else if (M == 2) {
        int longestPath[N];
        int longestPathLength = 0;
        findLongestPath(head, N, longestPath, &longestPathLength);
        for (int i = 0; i < longestPathLength; i++) {
            printf("%d ", longestPath[i]);
        }
        printf("\n");
    } else if (M == 3) {
        int longestPath1[N], longestPath2[N];
        int longestPathLength1 = 0, longestPathLength2 = 0;
        findLongestPath(head, N, longestPath1, &longestPathLength1);
        findLongestPath(head, N, longestPath2, &longestPathLength2);
        for (int i = 0; i < longestPathLength1; i++) {
            printf("%d ", longestPath1[i]);
        }
        printf("\n");
        for (int i = 0; i < longestPathLength2; i++) {
            printf("%d ", longestPath2[i]);
        }
        printf("\n");
    }

    pTask current = head;
    while (current != NULL) {
        pTask next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
