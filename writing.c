#include "sema.h"

union semun {
	int val
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *__buf;
}

int main() {
	
	int sem = semget(ftok(story.out, 1), 1);
	if(sem < 0) {
		printf("Error: %s", strerror(errno));
	}
	return 0
}

