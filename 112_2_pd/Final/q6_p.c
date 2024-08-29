#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int id;
    int time;
    int waitNodeNum;
    int waitNode[100];
    struct node_s * nexts[30];
    int nextCount;

} node_t;
typedef node_t * nodep;

int main(){
    int N, M, max;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &M);
        nodep nodes = (nodep)malloc(sizeof(nodep) * M);
        int *timeToSerch = (int *)malloc(sizeof(int) * M);
        for(int j=0; j<M; j++){
            scanf("%d %d", &nodes[j].time, &nodes[j].waitNodeNum);
            for(int k=0; k<nodes[j].waitNodeNum; k++){
                scanf("%d", &nodes[j].waitNode[k]);
            }
            timeToSerch[j] = nodes[j].time;
        }
        for(int j=0; j<M; j++){
            for(int k=0; k<nodes[j].waitNodeNum; k++){
                int nodeIndex = nodes[j].waitNode[k]-1;
                if(timeToSerch[nodeIndex] < timeToSerch[j] + nodes[nodeIndex].time)
                timeToSerch[nodeIndex] = timeToSerch[j] +nodes[nodeIndex].time;
            }
        }
        max = timeToSerch[0];
        for(int j=0; j<M; j++){
            if(max < timeToSerch[j]) max = timeToSerch[j];
        }
        printf("%d", max);
        free(timeToSerch);
        free(nodes);
    }
}