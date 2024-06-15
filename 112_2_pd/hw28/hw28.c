#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Task structure
typedef struct {
    int duration;        // Time to complete the task
    int numDependencies; // Number of tasks that depend on this one
    int *dependencies;   // List of tasks that depend on this one
    int earliestStart;   // Earliest start time
    int earliestFinish;  // Earliest finish time
} Task;

// Function to perform topological sorting and calculate completion times
void calculateProjectTime(Task *tasks, int numTasks) {
    int *inDegree = (int *)calloc(numTasks, sizeof(int));
    for (int i = 0; i < numTasks; i++) {
        for (int j = 0; j < tasks[i].numDependencies; j++) {
            int dep = tasks[i].dependencies[j];
            inDegree[dep]++;
        }
    }

    int *queue = (int *)malloc(numTasks * sizeof(int));
    int front = 0, rear = 0;
    // Initialize queue with tasks that have no incoming edges
    for (int i = 0; i < numTasks; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
            tasks[i].earliestStart = 0;
            tasks[i].earliestFinish = tasks[i].duration;
        }
    }

    // Process the queue
    while (front < rear) {
        int current = queue[front++];
        for (int i = 0; i < tasks[current].numDependencies; i++) {
            int next = tasks[current].dependencies[i];
            inDegree[next]--;
            if (inDegree[next] == 0) {
                queue[rear++] = next;
            }
            // Calculate the earliest start and finish times
            if (tasks[next].earliestStart < tasks[current].earliestFinish) {
                tasks[next].earliestStart = tasks[current].earliestFinish;
                tasks[next].earliestFinish = tasks[next].earliestStart + tasks[next].duration;
            }
        }
    }

    // Find the maximum of earliest finish times
    int maxFinishTime = 0;
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].earliestFinish > maxFinishTime) {
            maxFinishTime = tasks[i].earliestFinish;
        }
    }

    printf("%d\n", maxFinishTime);

    free(inDegree);
    free(queue);
}

int main() {
    int numProjects;
    scanf("%d", &numProjects);
    while (numProjects--) {
        int numTasks;
        scanf("%d", &numTasks);
        Task *tasks = (Task *)malloc(numTasks * sizeof(Task));
        for (int i = 0; i < numTasks; i++) {
            scanf("%d", &tasks[i].duration);
            int count;
            scanf("%d", &count);
            tasks[i].numDependencies = count;
            tasks[i].dependencies = (int *)malloc(count * sizeof(int));
            for (int j = 0; j < count; j++) {
                scanf("%d", &tasks[i].dependencies[j]);
                tasks[i].dependencies[j]--; // Adjust for 0-based index
            }
        }
        calculateProjectTime(tasks, numTasks);

        for (int i = 0; i < numTasks; i++) {free(tasks[i].dependencies);}
        free(tasks);
    }
    return 0;
}
