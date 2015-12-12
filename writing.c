#include "sema.h"

int main() {
	int sem = semget(ftok("story.out", 1), 1, 644 | IPC_CREAT);
	if(sem < 0) {
		printf("Error: %s", strerror(errno));
	}
	return 0;
}

