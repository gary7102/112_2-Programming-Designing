#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_s{
    int time;
    int waitNodeNum;
    int waitNode[100];
    struct node_t * next;
} node_t;
typedef node_t *nodep;
int main(){
    int M, N, max;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &M);
        nodep nodes = (nodep)malloc(sizeof(nodep) * M);
        int *timeToSearch = (int *)malloc(sizeof(int) * M);
        
        for(int j=0; j<M; j++){
            scanf("%d %d", &nodes[j].time, &nodes[j].waitNodeNum);
            for(int k=0; k<nodes[j].waitNodeNum; k++){
                scanf("%d", &nodes[j].waitNode[k]);
            }
            timeToSearch[j] = nodes[j].time;
        }

        for(int j=0; j<M; j++){
            for(int k=0; k<nodes[j].waitNodeNum; k++){
                int nodeIndex = nodes[j].waitNode[k]-1;
                if(timeToSearch[nodeIndex] < timeToSearch[j] + nodes[nodeIndex].time)
                timeToSearch[nodeIndex] = timeToSearch[j] + nodes[nodeIndex].time;
            }
        }

        max = timeToSearch[0];
        for(int j=0; j<M; j++){
            if(max < timeToSearch[j]) max = timeToSearch[j];
        }
        printf("%d\n", max);
        free(nodes);
        free(timeToSearch);
    }
    return 0;
}