#include <stdio.h>

int main() {
    int pid[15];        // Process IDs
    int bt[15];         // Burst times
    int n;
    // Get the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    // Get process IDs
    printf("Enter process ID of all the processes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pid[i]);
    }

    // Get burst times
    printf("Enter burst time of all the processes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    int wt[n];          // Waiting times

    // Waiting time for the first process is 0
    wt[0] = 0;

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }

    // Print the process table
    printf("Process ID Burst Time Waiting Time Turnaround Time\n");

    float twt = 0.0;    // Total waiting time
    float tat = 0.0;    // Total turnaround time

    for (int i = 0; i < n; i++) {
        printf("%d\t\t", pid[i]);     // Process ID
        printf("%d\t\t", bt[i]);      // Burst time
        printf("%d\t\t", wt[i]);      // Waiting time
        printf("%d\t\t", bt[i] + wt[i]); // Turnaround time
        printf("\n");

        // Calculate totals
        twt += wt[i];
        tat += (wt[i] + bt[i]);
    }

    // Calculate averages
    float awt = twt / n;    // Average waiting time
    float att = tat / n;    // Average turnaround time

    printf("Avg. waiting time = %.2f\n", awt);
    printf("Avg. turnaround time = %.2f", att);

    return 0;
}

