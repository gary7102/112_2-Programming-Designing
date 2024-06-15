#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    char data;
    struct node_s *right, *left;
} tree_t;

typedef tree_t* btree;

int findIndex(char* arr, int start, int end, char value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

btree buildTreePreIn(char* pre, int* preIndex, char* in, int inStart, int inEnd) {
    if (inStart > inEnd) return NULL;

    btree node = (btree)malloc(sizeof(tree_t));
    node->data = pre[*preIndex];
    node->left = node->right = NULL;
    (*preIndex)++;

    if (inStart == inEnd) return node;

    int inIndex = findIndex(in, inStart, inEnd, node->data);
    node->left = buildTreePreIn(pre, preIndex, in, inStart, inIndex - 1);
    node->right = buildTreePreIn(pre, preIndex, in, inIndex + 1, inEnd);

    return node;
}

btree buildTreeInPost(char* in, char* post, int* postIndex, int inStart, int inEnd) {
    if (inStart > inEnd) return NULL;

    btree node = (btree)malloc(sizeof(tree_t));
    node->data = post[*postIndex];
    node->left = node->right = NULL;
    (*postIndex)--;

    if (inStart == inEnd) return node;

    int inIndex = findIndex(in, inStart, inEnd, node->data);
    node->right = buildTreeInPost(in, post, postIndex, inIndex + 1, inEnd);
    node->left = buildTreeInPost(in, post, postIndex, inStart, inIndex - 1);

    return node;
}

void printLevelOrder(btree root) {
    if (!root) return;

    btree queue[100], temp;
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        temp = queue[front++];
        printf("%c", temp->data);
        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }
}

int main() {
    char type1, type2, A[21], B[21];
    scanf(" %c %s %c %s", &type1, A, &type2, B);

    btree root = NULL;
    int index = strlen(A) - 1;

    if (type1 == 'P' && type2 == 'I') {
        int preIndex = 0;
        root = buildTreePreIn(A, &preIndex, B, 0, index);
    } else if (type1 == 'I' && type2 == 'O') {
        root = buildTreeInPost(A, B, &index, 0, index);
    }

    printLevelOrder(root);
    return 0;
}
