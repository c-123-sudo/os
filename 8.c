#include <stdio.h>

int main() {

    // Input number of processes
    int n;
    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);

    // Declare necessary arrays and variables
    int wait_time = 0, ta_time = 0;
    int arr_time[n], burst_time[n], temp_burst_time[n];
    int x = n;   // Process count

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("Enter Details of Process %d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &arr_time[i]);

        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);

        temp_burst_time[i] = burst_time[i];
    }

    // Input time slot
    int time_slot;
    printf("Enter Time Slot: ");
    scanf("%d", &time_slot);

    // Initialize counters
    int total = 0, counter = 0, i = 0;

    printf("\nProcess ID\tBurst Time\tTurnaround Time\tWaiting Time\n");

    // Round Robin Scheduling
    for (total = 0; x != 0; ) {

        if (temp_burst_time[i] <= time_slot && temp_burst_time[i] > 0) {
            total += temp_burst_time[i];
            temp_burst_time[i] = 0;
            counter = 1;
        }
        else if (temp_burst_time[i] > 0) {
            temp_burst_time[i] -= time_slot;
            total += time_slot;
        }

        // When a process is completed
        if (temp_burst_time[i] == 0 && counter == 1) {
            x--;

            printf("\nProcess No %d\t\t%d\t\t%d\t\t%d",
                   i + 1,
                   burst_time[i],
                   total - arr_time[i],
                   total - arr_time[i] - burst_time[i]);

            wait_time += total - arr_time[i] - burst_time[i];
            ta_time += total - arr_time[i];

            counter = 0;
        }

        // Move to next process
        if (i == n - 1) {
            i = 0;
        }
        else if (arr_time[i + 1] <= total) {
            i++;
        }
        else {
            i = 0;
        }
    }

    // Calculate averages
    float average_wait_time = wait_time * 1.0 / n;
    float average_turnaround_time = ta_time * 1.0 / n;

    printf("\nAverage Waiting Time: %.2f", average_wait_time);
    printf("\nAverage Turnaround Time: %.2f", average_turnaround_time);

    return 0;
}
