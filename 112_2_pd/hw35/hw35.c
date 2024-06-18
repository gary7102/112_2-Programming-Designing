#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    int time;
    int waitNodeNum;
    int waitNode[100];
    struct node_s* next;
} node_t;

typedef node_t* nodep;

// Utility function to create a new node
nodep create_node(int time, int waitNodeNum, int* waitNode) {
    nodep newNode = (nodep)malloc(sizeof(node_t));
    newNode->time = time;
    newNode->waitNodeNum = waitNodeNum;
    memcpy(newNode->waitNode, waitNode, waitNodeNum * sizeof(int));
    newNode->next = NULL;
    return newNode;
}

// Function to calculate project completion time
int calculate_completion_time(nodep* nodes, int nodeCount) {
    int *indegree = (int*)calloc(nodeCount, sizeof(int));
    int *earliestStart = (int*)calloc(nodeCount, sizeof(int));

    // Calculate indegrees
    for (int i = 0; i < nodeCount; i++) {
        for (int j = 0; j < nodes[i]->waitNodeNum; j++) {
            indegree[nodes[i]->waitNode[j] - 1]++;
        }
    }

    // Queue for nodes with no incoming edges
    int *queue = (int*)malloc(nodeCount * sizeof(int));
    int front = 0, rear = 0;

    // Enqueue all nodes with zero indegree
    for (int i = 0; i < nodeCount; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
            earliestStart[i] = nodes[i]->time;
        }
    }

    // Process the nodes
    while (front < rear) {
        int currentNode = queue[front++];
        for (int i = 0; i < nodes[currentNode]->waitNodeNum; i++) {
            int nextNode = nodes[currentNode]->waitNode[i] - 1;
            indegree[nextNode]--;
            if (indegree[nextNode] == 0) {
                queue[rear++] = nextNode;
            }
            if (earliestStart[nextNode] < earliestStart[currentNode] + nodes[nextNode]->time) {
                earliestStart[nextNode] = earliestStart[currentNode] + nodes[nextNode]->time;
            }
        }
    }

    // Find maximum time required
    int maxTime = 0;
    for (int i = 0; i < nodeCount; i++) {
        if (maxTime < earliestStart[i]) {
            maxTime = earliestStart[i];
        }
    }

    free(indegree);
    free(queue);
    free(earliestStart);

    return maxTime;
}

int main() {
    int N; // Number of projects
    scanf("%d", &N);

    while (N--) {
        int M; // Number of tasks
        scanf("%d", &M);

        nodep nodes[M];
        for (int i = 0; i < M; i++) {
            int time, K;
            scanf("%d %d", &time, &K);
            int waitNode[K];
            for (int j = 0; j < K; j++) {
                scanf("%d", &waitNode[j]);
            }
            nodes[i] = create_node(time, K, waitNode);
        }

        int completionTime = calculate_completion_time(nodes, M);
        printf("%d\n", completionTime);

        // Free memory
        for (int i = 0; i < M; i++) {
            free(nodes[i]);
        }
    }
    return 0;
}
