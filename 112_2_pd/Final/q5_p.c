#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct  node_s { 
    char data; 
    struct node_s * right, * left; 
} tree_t; 
typedef   tree_t* btree; 

tree_t* newNode(char data){
    tree_t* node = (tree_t*)malloc(sizeof(tree_t));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(char arr[], int start, int end, char data){
    for(int i=start; i<=end; i++){
        if(arr[i] == data) return i;
    }
    return -1;
}

tree_t* buildTreePreIn(char in[], char pre[], int inStart, int inEnd, int *preIndex){
    if(inStart>inEnd) return NULL;

    tree_t* tNode = newNode(pre[*preIndex]);
    (*preIndex)++;

    if(inStart == inEnd) return tNode;

    int index = search(in, inStart, inEnd, tNode->data);
    tNode->left = buildTreePreIn(in, pre, inStart, index-1, preIndex);
    tNode->right = buildTreePreIn(in, pre, index+1, inEnd, preIndex);
    return tNode;
}

tree_t* buildTreePostIn(char in[], char post[], int inStart, int inEnd, int *postIndex){
    if(inStart>inEnd) return NULL;

    tree_t* tNode = newNode(post[*postIndex]);
    (*postIndex)--;

    if(inStart == inEnd) return tNode;

    int index = search(in, inStart, inEnd, tNode->data);
    tNode->right = buildTreePostIn(in, post, index+1, inEnd, postIndex);
    tNode->left = buildTreePostIn(in, post, inStart, index-1, postIndex);
    return tNode;
}

void BFS(tree_t* root){
    if(root == NULL) return;

    int front = 0, rear = 0;
    tree_t* queue[100];

    queue[rear++] = root;
    while(front < rear){
        tree_t* current = queue[front++];
        printf("%c", current->data);

        if(current->left != NULL) queue[rear++] = current->left;
        if(current->right != NULL) queue[rear++] = current->right;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    char traverseType1, traverseType2;
    char traverseData1[100], traverseData2[100];

    scanf(" %c", &traverseType1);
    scanf("%s", traverseData1);
    scanf(" %c", &traverseType2);
    scanf("%s", traverseData2);

    tree_t* root = NULL;
    int index = 0;

    if(traverseType1 == 'P' && traverseType2 == 'I'){
        index = 0;
        root = buildTreePreIn(traverseData2, traverseData1, 0, n-1, &index);
    } 
    else if(traverseType1 == 'O' && traverseType2 == 'I'){
        index = n-1;
        root = buildTreePostIn(traverseData2, traverseData1, 0, n-1, &index);
    }
    BFS(root);
}