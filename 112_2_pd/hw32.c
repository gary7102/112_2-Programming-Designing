#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dnode_s {
    int data;
    struct dnode_s *front;
    struct dnode_s *back;
} node_t;

typedef node_t* nodep_t;

// Function prototypes
void addFront(nodep_t* head, nodep_t* tail, int data);
void addBack(nodep_t* head, nodep_t* tail, int data);
void removeFront(nodep_t* head, nodep_t* tail);
void removeBack(nodep_t* head, nodep_t* tail);
void empty(nodep_t* head, nodep_t* tail);
void insert(nodep_t* head, nodep_t* tail, int position, int data);
void removeN(nodep_t* head, nodep_t* tail, int position);
void print(nodep_t head);

int main() {
    int N;
    scanf("%d", &N);

    nodep_t head = NULL, tail = NULL;

    for (int i = 0; i < N; i++) {
        char command[20];
        int data, position;
        scanf("%s", command);

        if (strcmp(command, "addFront") == 0) {
            scanf("%d", &data);
            addFront(&head, &tail, data);
        } else if (strcmp(command, "addBack") == 0) {
            scanf("%d", &data);
            addBack(&head, &tail, data);
        } else if (strcmp(command, "removeFront") == 0) {
            removeFront(&head, &tail);
        } else if (strcmp(command, "removeBack") == 0) {
            removeBack(&head, &tail);
        } else if (strcmp(command, "empty") == 0) {
            empty(&head, &tail);
        } else if (strcmp(command, "insert") == 0) {
            scanf("%d %d", &position, &data);
            insert(&head, &tail, position, data);
        } else if (strcmp(command, "remove") == 0) {
            scanf("%d", &position);
            removeN(&head, &tail, position);
        } else if (strcmp(command, "print") == 0) {
            print(head);
        }
    }

    return 0;
}

void addFront(nodep_t* head, nodep_t* tail, int data) {
    nodep_t newNode = (nodep_t)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->front = NULL;
    newNode->back = *head;

    if (*head != NULL) {
        (*head)->front = newNode;
    } else {
        *tail = newNode;
    }

    *head = newNode;
}

void addBack(nodep_t* head, nodep_t* tail, int data) {
    nodep_t newNode = (nodep_t)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->back = NULL;
    newNode->front = *tail;

    if (*tail != NULL) {
        (*tail)->back = newNode;
    } else {
        *head = newNode;
    }

    *tail = newNode;
}

void removeFront(nodep_t* head, nodep_t* tail) {
    if (*head == NULL) {
        printf("Double link list is empty\n");
        return;
    }

    nodep_t temp = *head;
    *head = (*head)->back;

    if (*head != NULL) {
        (*head)->front = NULL;
    } else {
        *tail = NULL;
    }

    free(temp);
}

void removeBack(nodep_t* head, nodep_t* tail) {
    if (*tail == NULL) {
        printf("Double link list is empty\n");
        return;
    }

    nodep_t temp = *tail;
    *tail = (*tail)->front;

    if (*tail != NULL) {
        (*tail)->back = NULL;
    } else {
        *head = NULL;
    }

    free(temp);
}

void empty(nodep_t* head, nodep_t* tail) {
    if (*head == NULL) {
        printf("Double link list is empty\n");
        return;
    }

    while (*head != NULL) {
        removeFront(head, tail);
    }
}

void insert(nodep_t* head, nodep_t* tail, int position, int data) {
    if (position < 1) {
        printf("Invalid command\n");
        return;
    }

    nodep_t current = *head;
    int count = 1;

    while (current != NULL && count < position) {
        current = current->back;
        count++;
    }

    if (current == NULL) {
        printf("Invalid command\n");
        return;
    }

    nodep_t newNode = (nodep_t)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->front = current;
    newNode->back = current->back;

    if (current->back != NULL) {
        current->back->front = newNode;
    } else {
        *tail = newNode;
    }

    current->back = newNode;
}

void removeN(nodep_t* head, nodep_t* tail, int position) {
    if (position < 1) {
        printf("Invalid command\n");
        return;
    }

    nodep_t current = *head;
    int count = 1;

    while (current != NULL && count < position) {
        current = current->back;
        count++;
    }

    if (current == NULL) {
        printf("Invalid command\n");
        return;
    }

    if (current->front != NULL) {
        current->front->back = current->back;
    } else {
        *head = current->back;
    }

    if (current->back != NULL) {
        current->back->front = current->front;
    } else {
        *tail = current->front;
    }

    free(current);
}

void print(nodep_t head) {
    if (head == NULL) {
        printf("Double link list is empty\n");
        return;
    }

    nodep_t current = head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->back;
    }
}
