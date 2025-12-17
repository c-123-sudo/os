#include<stdio.h>
int main() {
	/* array will store at most 5 processes with 3 resources.
	   If your processes or resources are greater than 5 and 3,
	   then increase the size of the arrays */
	int p, c, count = 0, i, j, alc[5][3], max[5][3], need[5][3], safe[5], available[3], done[5], terminate = 0;
	// Input number of processes and resources
	printf("Enter the number of processes and resources: ");
	scanf("%d %d", &p, &c);
	// Input allocation matrix
	printf("Enter the allocation matrix for resources of all processes (%dx%d matrix):\n", p, c);
	for (i = 0; i < p; i++) {
		for (j = 0; j < c; j++) {
			scanf("%d", &alc[i][j]);
		}
	}
	// Input max resources required for each process
	printf("Enter the max resource requirements for each process (%dx%d matrix):\n", p, c);
	
		for (i = 0; i < p; i++) {
			for (j = 0; j < c; j++) {
				scanf("%d", &max[i][j]);
			}
		}
	// Input available resources
	printf("Enter the available resources: ");
	for (i = 0; i < c; i++) {
		scanf("%d", &available[i]);
	}
	// Compute the need matrix (Need = Max - Allocation)
	printf("\nNeed resources matrix is:\n");
	for (i = 0; i < p; i++) {
		for (j = 0; j < c; j++) {
			need[i][j] = max[i][j] - alc[i][j];
			printf("%d\t", need[i][j]);
		}
		printf("\n");
	}
	// Initialize the done array to track if a process has completed
	for (i = 0; i < p; i++) {
		done[i] = 0;
	}
	// Safety algorithm to find the safe sequence
	while (count < p) {
		for (i = 0; i < p; i++) {
			if (done[i] == 0) {
				for (j = 0; j < c; j++) {
					if (need[i][j] > available[j]) {
						break; // If need is greater than available, skip the process
					}
				}
				// If the process can proceed (i.e., need <= available), then it will execute
				if (j == c) {
					safe[count] = i; // Add the process to the safe sequence
					done[i] = 1; // Mark the process as done
						     // Release resources held by the process and update available resources
					
						for (j = 0; j < c; j++) {
							available[j] += alc[i][j];
						}
					count++;
					terminate = 0;
				} else {
					terminate++; // Process cannot be executed at this moment
				}
			}
		}
		// If no process could be executed, it means no safe sequence exists
		if (terminate == p) {
			printf("Safe sequence does not exist\n");
			break;
		}
	}
	// If we found a safe sequence, print the results
	if (terminate != p) {
		printf("\nAvailable resources after completion:\n");
		for (i = 0; i < c; i++) {
			printf("%d\t", available[i]);
		}
		printf("\nSafe sequence is:\n");
		for (i = 0; i < p; i++) {
			printf("p%d\t", safe[i]);
		}
		printf("\n");
	}
	return 0;
}
