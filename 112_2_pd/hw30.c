#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    int data;
    struct node_s *next;
} node_t;

typedef node_t* nodep_t;

typedef struct {
    nodep_t front;
    nodep_t rear;
} Queue;

nodep_t createNode(int data) {
    nodep_t newNode = (nodep_t)malloc(sizeof(node_t));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

void push(Queue *q, int data) {
    nodep_t newNode = createNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

void pop(Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    nodep_t temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    printf("%d\n", temp->data);
    free(temp);
}

void front(Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("%d\n", q->front->data);
}

void empty(Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    nodep_t temp;
    while (q->front != NULL) {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    q->rear = NULL;
}

void print(Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    nodep_t temp = q->front;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    Queue queue;
    initQueue(&queue);
    for (int i = 0; i < N; i++) {
        char operation[10];
        scanf("%s", operation);
        if (strcmp(operation, "push") == 0) {
            int data;
            scanf("%d", &data);
            push(&queue, data);
        } else if (strcmp(operation, "pop") == 0) {
            pop(&queue);
        } else if (strcmp(operation, "front") == 0) {
            front(&queue);
        } else if (strcmp(operation, "empty") == 0) {
            empty(&queue);
        } else if (strcmp(operation, "print") == 0) {
            print(&queue);
        }
    }
    return 0;
}