#include <stdio.h>
#include <stdbool.h>
#define MAX_PROCESSES 100

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;  // Added to track completion time
};

int main()
{
    int n;
    struct process processes[MAX_PROCESSES];
    bool completed[MAX_PROCESSES] = { false };
    int current_time = 0;
    int shortest_index = 0;
    int completed_count = 0;  // Track number of completed processes
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d",
              &processes[i].arrival_time,
              &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completion_time = 0;
    }
    printf("\n");
    
    // Process scheduling loop
    while (completed_count < n) {
        shortest_index = -1;
        
        // Find process with shortest remaining time
        for (int i = 0; i < n; i++) {
            if (!completed[i] && processes[i].arrival_time <= current_time) {
                if (shortest_index == -1 ||
                    processes[i].remaining_time < processes[shortest_index].remaining_time) {
                    shortest_index = i;
                }
            }
        }
        
        if (shortest_index != -1) {
            // Execute the selected process for 1 time unit
            processes[shortest_index].remaining_time--;
            
            // Check if process is completed
            if (processes[shortest_index].remaining_time == 0) {
                completed[shortest_index] = true;
                completed_count++;
                processes[shortest_index].completion_time = current_time + 1;
            }
        }
        
        current_time++;
    }
    
    // Display the results
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    
    for (int i = 0; i < n; i++) {
        int turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        int waiting_time = turnaround_time - processes[i].burst_time;
        
        total_waiting_time += waiting_time;
        total_turnaround_time += turnaround_time;
        
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].pid,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].completion_time,
               turnaround_time,
               waiting_time);
    }
    
    float avg_waiting_time = (float) total_waiting_time / n;
    float avg_turnaround_time = (float) total_turnaround_time / n;
    
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    
    return 0;
}	



