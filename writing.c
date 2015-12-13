#include "sema.h"

int main() {
	int sem = semget(ftok("story.out", 1), 1, 666 | IPC_CREAT);
	if(sem < 0) {
		printf("Error: %s", strerror(errno));
	}
	struct sembuf enter;
	enter.sem_flg = SEM_UNDO;
	enter.sem_op = -1;
	enter.sem_num = 0;
	int check = semop(sem, &enter, 1);
	if(check < 0) {
		printf("Error: %s", strerror(errno));
	}

	return 0;
}

