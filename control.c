#include "sema.h"

int main(int argc, char *argv[]) {
	int f, sh, sem;
	int shkey = ftok("story", 0);
	int smkey = ftok("story", 1);
	if(!strcmp(argv[1], "-r")) {
		sh = shmget(shkey, sizeof(int), 0644);
		sem = semget(smkey, sizeof(int), 0644);
		int check = shmctl(sh, IPC_RMID, NULL);
		if(check == -1) {
			printf("Error: %s\n", strerror(errno));
		}
		check = semctl(sem, 0, IPC_RMID);
		if(check == -1) {
			printf("Error: %s\n", strerror(errno));
		}
		printf("hi\n");
		f = open("story", O_RDONLY, 0444);
		if(check == -1) {
			printf("Error: %s\n", strerror(errno));
		}
		struct stat sfile;
		stat("story", &sfile);
		char fst[sfile.st_size];
		check = read(check, fst, sfile.st_size);
		if(check == -1) {
			printf("Error: %s\n", strerror(errno));
		}
		printf("%s\n", fst);
		close(f);
	}
	else if(!strcmp(argv[1], "-c")) {
		f = open("story", O_CREAT | O_RDWR, 0666);
		if(f < 0) {
			printf("Error: %s\n", strerror(errno));
		}
		sh = shmget(shkey, sizeof(int), 0666 | IPC_CREAT);
		if(sh < 0) {
			printf("Error: %s\n", strerror(errno));
		}
		sem = semget(smkey, 1, IPC_CREAT);
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
