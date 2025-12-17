#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#define SEGSIZE 100
int main(int argc, char *argv[])
{
	int shmid, cntr;
	key_t key;
	char *segptr;
	char buff[] = "poooda";
	// Generate a unique key for shared memory segment
	key = ftok(".", 's');
	// Try to get the shared memory segment, create if not exists
	if((shmid = shmget(key, SEGSIZE, IPC_CREAT | IPC_EXCL | 0666)) == -1)
	{
		// If shared memory already exists, just get it
		{ if((shmid = shmget(key, SEGSIZE, 0)) == -1)
			
				perror("shmget");
			exit(1);
		}
	}
	else
	{
		printf("Creating a new shared memory segment \n");
		printf("SHMID: %d\n", shmid);
	}
	// Display all shared memory segments
	system("ipcs -m");
	// Attach the shared memory segment to process's address space
	if((segptr = (char*)shmat(shmid, 0, 0)) == (char*) -1)
	{
		perror("shmat");
		exit(1);
	}
	// Writing data to shared memory
	printf("Writing data to shared memory...\n");
	strcpy(segptr, buff);
	printf("DONE\n");
	// Reading data from shared memory
	printf("Reading data from shared memory...\n");
	printf("DATA: %s\n", segptr);
	printf("DONE\n");
	// Removing shared memory segment
	printf("Removing shared memory segment...\n");
	if(shmctl(shmid, IPC_RMID, 0) == -1)
		printf("Can't remove shared memory segment...\n");
	else
		printf("Removed successfully\n");
	return 0;
}
