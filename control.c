#include "sema.h"

int main(int argc, char *argv[]) {
	int f, sh, sem;
	if(!strcmp(argv[1], "-r")) {
		shmctl(sh, IPC_RMID);
		semctl(sem, 0, IMP_RMID);
	}
	else if(!strcmp(argv[1], "-c")) {
		f = open("story.out", O_CREAT, 644);
		if(f < 0) {
			printf("Error: %s", strerror(errno));
		}
		sh = shmget(ftok(story.out, 17), sizeof(int), 644 | IPC_CREAT);
		if(sh < 0) {
			printf("Error: %s", strerror(errno));
		}
		sem = semget(ftok(story.out, 18), 1, IPC_CREAT);
		if(sem < 0) {
			printf("Error: %s", strerror(errno));
		}
	}
	else {
		printf("No input");
		return 0;
	}
}
