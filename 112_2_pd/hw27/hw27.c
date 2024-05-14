#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int machine;
    int time;
} Operation;

typedef struct {
    int num_operations;
    Operation *operations;
    int completion_time;
    int current_operation;
} Task;

typedef struct {
    int available_time;
} Machine;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    Task tasks[M];
    Machine machines[N];

    // Initialize machines' available time to 0
    for (int i = 0; i < N; i++) {
        machines[i].available_time = 0;
    }

    // Read tasks and their operations
    for (int i = 0; i < M; i++) {
        scanf("%d", &tasks[i].num_operations);
        tasks[i].operations = (Operation *)malloc(tasks[i].num_operations * sizeof(Operation));
        for (int j = 0; j < tasks[i].num_operations; j++) {
            scanf("%d %d", &tasks[i].operations[j].machine, &tasks[i].operations[j].time);
        }
        tasks[i].completion_time = 0;
        tasks[i].current_operation = 0;
    }

    int tasks_completed = 0;
    while (tasks_completed < M) {
        int min_completion_time = INT_MAX;
        int selected_task = -1;

        // Find the task with the earliest completion time for its next operation
        for (int i = 0; i < M; i++) {
            if (tasks[i].current_operation < tasks[i].num_operations) {
                int op_index = tasks[i].current_operation;
                int machine = tasks[i].operations[op_index].machine;
                int time = tasks[i].operations[op_index].time;
                int start_time = tasks[i].completion_time > machines[machine].available_time ? tasks[i].completion_time : machines[machine].available_time;
                int completion_time = start_time + time;

                if (completion_time < min_completion_time || (completion_time == min_completion_time && i < selected_task)) {
                    min_completion_time = completion_time;
                    selected_task = i;
                }
            }
        }

        // Schedule the selected operation
        if (selected_task != -1) {
            int op_index = tasks[selected_task].current_operation;
            int machine = tasks[selected_task].operations[op_index].machine;
            int time = tasks[selected_task].operations[op_index].time;
            int start_time = tasks[selected_task].completion_time > machines[machine].available_time ? tasks[selected_task].completion_time : machines[machine].available_time;
            int completion_time = start_time + time;

            machines[machine].available_time = completion_time;
            tasks[selected_task].completion_time = completion_time;
            tasks[selected_task].current_operation++;

            // Check if this task is completed
            if (tasks[selected_task].current_operation == tasks[selected_task].num_operations) {
                tasks_completed++;
            }
        }
    }

    // Calculate the total completion time
    int total_completion_time = 0;
    for (int i = 0; i < M; i++) {
        total_completion_time += tasks[i].completion_time;
        free(tasks[i].operations);
    }

    printf("%d\n", total_completion_time);

    return 0;
}
