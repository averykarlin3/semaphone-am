#include "sema.h"

int main(int argc, char *argv[]) {
	int f, sh, sem;
	if(!strcmp(argv[1], "-r")) {
		int check = shmctl(sh, IPC_RMID, NULL);
		if(check == -1) {
			printf("Error: %s\n", strerror(errno));
		}
		check = semctl(sem, 0, IPC_RMID);
		if(check == -1) {
			printf("Error: %s\n", strerror(errno));
		}
		f = open("story.out", O_RDONLY, 444);
		if(check == -1) {
			printf("Error: %s\n", strerror(errno));
		}
		struct stat sfile;
		stat("story.out", &sfile);
		char fst[sfile.st_size];
		check = read(check, fst, sfile.st_size);
		if(check == -1) {
			printf("Error: %s\n", strerror(errno));
		}
		printf("%s\n", fst);
		close(f);
	}
	else if(!strcmp(argv[1], "-c")) {
		f = open("story.out", O_CREAT | O_RDWR, 666);
		if(f < 0) {
			printf("Error: %s\n", strerror(errno));
		}
		sh = shmget(ftok("story.out", 0), sizeof(int), 666 | IPC_CREAT);
		if(sh < 0) {
			printf("Error: %s\n", strerror(errno));
		}
		sem = semget(ftok("story.out", 1), 1, IPC_CREAT);
		if(sem < 0) {
			printf("Error: %s\n", strerror(errno));
		}
		close(f);
	}
	else {
		printf("No input");
		return 0;
	}
	return 0;
}
