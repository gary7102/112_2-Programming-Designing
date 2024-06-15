#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CITIES 50

typedef struct {
    int cities[MAX_CITIES];
    int count;
} Path;

int graph[MAX_CITIES][MAX_CITIES];
bool visited[MAX_CITIES];
Path paths[MAX_CITIES];
int queue[MAX_CITIES], front, rear;

void enqueue(int city) {
    queue[rear++] = city;
}

int dequeue() {
    return queue[front++];
}

bool isEmpty() {
    return front == rear;
}

void bfs(int start, int num_cities) {
    enqueue(start);
    visited[start] = true;
    paths[start].cities[paths[start].count++] = start;

    while (!isEmpty()) {
        int current = dequeue();
        for (int i = 0; i < num_cities; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = true;
                enqueue(i);
                paths[i].count = paths[current].count + 1;
                memcpy(paths[i].cities, paths[current].cities, sizeof(int) * paths[current].count);
                paths[i].cities[paths[current].count] = i;
            }
        }
    }
}

int main() {
    int N, X, Z, Y = -1;
    char line[100], *token;

    // Read the first line and parse N, X, Z, and optionally Y
    fgets(line, sizeof(line), stdin);
    token = strtok(line, " ");
    N = atoi(token);
    token = strtok(NULL, " ");
    X = atoi(token);
    token = strtok(NULL, " ");
    Z = atoi(token);
    token = strtok(NULL, " ");
    if (token != NULL) Y = atoi(token);

    int city1, city2;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &city1, &city2);
        graph[city1][city2] = 1;
        graph[city2][city1] = 1;  // Assume bidirectional roads
    }

    memset(visited, false, sizeof(visited));
    front = rear = 0;

    if (Y >= 0) {
        bfs(X, MAX_CITIES);
        if (!visited[Y]) {
            printf("NO\n");
            return 0;
        }
        Path pathXtoY = paths[Y];

        memset(visited, false, sizeof(visited));
        memset(paths, 0, sizeof(paths));
        front = rear = 0;

        bfs(Y, MAX_CITIES);
        if (!visited[Z]) {
            printf("NO\n");
            return 0;
        }
        Path pathYtoZ = paths[Z];

        printf("%d\n", pathXtoY.count + pathYtoZ.count - 1-1);
        for (int i = 0; i < pathXtoY.count; i++) {
            printf("%d ", pathXtoY.cities[i]);
        }
        for (int i = 1; i < pathYtoZ.count; i++) {  // Start from 1 to avoid repeating Y
            printf("%d ", pathYtoZ.cities[i]);
        }
        printf("\n");
    } else {
        bfs(X, MAX_CITIES);
        if (!visited[Z]) {
            printf("NO\n");
            return 0;
        }
        printf("%d\n", paths[Z].count-1);
        for (int i = 0; i < paths[Z].count; i++) {
            printf("%d ", paths[Z].cities[i]);
        }
        printf("\n");
    }

    return 0;
}