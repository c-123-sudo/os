#include <stdio.h>
int main() {
	int bt[20], p[20], wt[20], tat[20], i, j, n, total = 0, totalT = 0, pos, temp;
	float avg_wt, avg_tat;
	// Get the number of processes
	printf("Enter number of processes: ");
	scanf("%d", &n);
	// Get burst times for each process
	printf("\nEnter Burst Time:\n");
	for (i = 0; i < n; i++) {
		printf("p%d: ", i + 1);
		scanf("%d", &bt[i]);
		p[i] = i + 1;
	}
	// Sorting of burst times in ascending order
	for (i = 0; i < n; i++) {
		pos = i;
		for (j = i + 1; j < n; j++) {
			
				if (bt[j] < bt[pos]) {
					pos = j;
				}
		}
		// Swap burst times
		temp = bt[i];
		bt[i] = bt[pos];
		bt[pos] = temp;
		// Swap process IDs
		temp = p[i];
		p[i] = p[pos];
		p[pos] = temp;
	}
	wt[0] = 0; // Waiting time for the first process is 0
		   // Calculating waiting time for all processes
	for (i = 1; i < n; i++) {
		wt[i] = 0;
		for (j = 0; j < i; j++) {
			// Individual WT by adding burst time of all previous completed processes
			wt[i] += bt[j];
		}
		// Total waiting time
		total += wt[i];
	}
	// Calculate average waiting time
	avg_wt = (float)total / n;
	// Printing Process Details
	printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time");
	for (i = 0; i < n; i++) {
		// Turnaround time for each process
		tat[i] = bt[i] + wt[i];
		// Total turnaround time
		totalT += tat[i];
		// Displaying process details
		printf("\np%d\t\t %d\t\t %d\t\t\t%d", p[i], bt[i], wt[i], tat[i]);
	}
	// Calculate average turnaround time
	avg_tat = (float)totalT / n;

		// Display averages
		printf("\n\nAverage Waiting Time = %.2f", avg_wt);
	printf("\nAverage Turnaround Time = %.2f", avg_tat);
	return 0;
}
