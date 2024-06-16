//LinkList建構唯一二元樹 hw34
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of the tree node
typedef struct node_s {
    char data;
    struct node_s *right, *left;
} tree_t;

typedef tree_t* btree;

// Function to create a new tree node
tree_t* newNode(char data) {
    tree_t* node = (tree_t*)malloc(sizeof(tree_t));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to search for a character in a string
int search(char arr[], int strt, int end, char value) {
    for (int i = strt; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Function to build the tree from preorder and inorder traversal
tree_t* buildTreePreIn(char in[], char pre[], int inStrt, int inEnd, int* preIndex) {
    if (inStrt > inEnd)
        return NULL;

    tree_t* tNode = newNode(pre[*preIndex]);
    (*preIndex)++;

    if (inStrt == inEnd)
        return tNode;

    int inIndex = search(in, inStrt, inEnd, tNode->data);
    // printf("inIndex = %d\n", inIndex);
    tNode->left = buildTreePreIn(in, pre, inStrt, inIndex - 1, preIndex);
    tNode->right = buildTreePreIn(in, pre, inIndex + 1, inEnd, preIndex);

    return tNode;
}

// Function to build the tree from postorder and inorder traversal
tree_t* buildTreePostIn(char in[], char post[], int inStrt, int inEnd, int* postIndex) {
    if (inStrt > inEnd)
        return NULL;

    tree_t* tNode = newNode(post[*postIndex]);
    (*postIndex)--;

    if (inStrt == inEnd)
        return tNode;

    int inIndex = search(in, inStrt, inEnd, tNode->data);

    tNode->right = buildTreePostIn(in, post, inIndex + 1, inEnd, postIndex);
    tNode->left = buildTreePostIn(in, post, inStrt, inIndex - 1, postIndex);

    return tNode;
}

// Function to print the level order traversal of the tree
void printLevelOrder(tree_t* root) {
    if (root == NULL)
        return;

    int rear = 0, front = 0;
    tree_t* queue[100];

    queue[rear++] = root;

    while (front < rear) {
        tree_t* current = queue[front++];

        printf("%c", current->data);

        if (current->left != NULL)
            queue[rear++] = current->left;

        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char traversalType1, traversalType2;
    char traversalData1[100], traversalData2[100];

    scanf(" %c", &traversalType1);
    scanf("%s", traversalData1);
    scanf(" %c", &traversalType2);
    scanf("%s", traversalData2);

    btree root = NULL;
    int index;

    if (traversalType1 == 'P' && traversalType2 == 'I') {
        index = 0;
        root = buildTreePreIn(traversalData2, traversalData1, 0, n - 1, &index);
    } else if (traversalType1 == 'O' && traversalType2 == 'I') {
        index = n - 1;
        root = buildTreePostIn(traversalData2, traversalData1, 0, n - 1, &index);
    }

    printLevelOrder(root);

    return 0;
}
