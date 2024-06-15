#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int machine;
    int time;
    struct node_s* next;
} node_t;

typedef struct {
    node_t* operations;  // Head of the operations list
    node_t* last_op;     // Last operation pointer (for appending new operations)
    int current_time;    // When this job will be completely processed
} job_t;


// Create a new node for the linked list
node_t* create_node(int machine, int time) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->machine = machine;
    new_node->time = time; // Correct assignment of the time variable
    new_node->next = NULL;
    return new_node;
}


// Append a new operation to the job's operation list
void append_operation(job_t* job, int machine, int time) {
    node_t* new_node = create_node(machine, time);
    if (job->operations == NULL) {
        job->operations = job->last_op = new_node;
    } else {
        job->last_op->next = new_node;
        job->last_op = new_node;
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    int machine_free_times[N];
    job_t jobs[M];

    // Initialize machine free times and jobs
    for (int i = 0; i < N; i++) {
        machine_free_times[i] = 0;
    }

    for (int i = 0; i < M; i++) {
        jobs[i].operations = NULL;
        jobs[i].last_op = NULL;
        jobs[i].current_time = 0;

        int P;
        scanf("%d", &P);
        for (int j = 0; j < P; j++) {
            int K, T;
            scanf("%d %d", &K, &T);
            append_operation(&jobs[i], K, T);
        }
    }

    // Job scheduling simulation
    int total_completed_time = 0;
    int jobs_completed = 0;

    while (jobs_completed < M) {
        int min_end_time = __INT_MAX__;
        int selected_job_index = -1;
        node_t* selected_job_operation = NULL;

        // Determine the earliest job operation that can be scheduled
        for (int i = 0; i < M; i++) {
            if (jobs[i].operations != NULL) {
                int start_time = jobs[i].current_time;
                int machine_index = jobs[i].operations->machine;
                int process_time = jobs[i].operations->time;

                int earliest_start = (machine_free_times[machine_index] > start_time) ? machine_free_times[machine_index] : start_time;
                int expected_end = earliest_start + process_time;

                if (expected_end < min_end_time || (expected_end == min_end_time && selected_job_index > i)) {
                    min_end_time = expected_end;
                    selected_job_index = i;
                    selected_job_operation = jobs[i].operations;
                }
            }
        }

        // Update the job and machine tracking
        if (selected_job_index != -1) {
            int machine_index = selected_job_operation->machine;
            int process_time = selected_job_operation->time;

            int start_time = (machine_free_times[machine_index] > jobs[selected_job_index].current_time) ? machine_free_times[machine_index] : jobs[selected_job_index].current_time;
            machine_free_times[machine_index] = start_time + process_time;
            jobs[selected_job_index].current_time = machine_free_times[machine_index];

            // Move to the next operation for the selected job
            jobs[selected_job_index].operations = selected_job_operation->next;
            free(selected_job_operation); // Free the processed node

            // Check if the job is completed
            if (jobs[selected_job_index].operations == NULL) {
                total_completed_time += jobs[selected_job_index].current_time;
                jobs_completed++;
            }
        }
    }

    printf("%d\n", total_completed_time);
    return 0;
}
