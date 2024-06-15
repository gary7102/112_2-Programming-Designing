#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    int data;
    struct node_s *next;
} node_t;

typedef node_t* nodep_t;

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

void push(nodep_t *top, int data) {
    nodep_t newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

void pop(nodep_t *top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    nodep_t temp = *top;
    *top = (*top)->next;
    printf("%d\n", temp->data);
    free(temp);
}

void top(nodep_t top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("%d\n", top->data);
}

void empty(nodep_t *top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    nodep_t temp;
    while (*top != NULL) {
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

void print(nodep_t top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    nodep_t temp = top;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    nodep_t stack = NULL;
    for (int i = 0; i < N; i++) {
        char operation[10];
        scanf("%s", operation);
        if (strcmp(operation, "push") == 0) {
            int data;
            scanf("%d", &data);
            push(&stack, data);
        } else if (strcmp(operation, "pop") == 0) {
            pop(&stack);
        } else if (strcmp(operation, "top") == 0) {
            top(stack);
        } else if (strcmp(operation, "empty") == 0) {
            empty(&stack);
        } else if (strcmp(operation, "print") == 0) {
            print(stack);
        }
    }
    return 0;
}
