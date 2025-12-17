#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // Required for the exit() function

int main() {
    int pid, pid1, pid2;

    pid = fork(); // Create a new process

    if (pid == -1) {
        // If fork fails
        printf("ERROR IN PROCESS CREATION\n");
        exit(1); // Exit the program if process creation fails
    }

    if (pid != 0) {
        // Parent process
        pid1 = getpid(); // Get the process ID of the parent
        printf("\nThe parent process ID is %d %d\n", pid1,pid);
    } else {
        // Child process
        pid2 = getpid(); // Get the process ID of the child
        printf("\nThe child process ID is %d %d \n", pid2,pid);
    }
    return 0;
}

