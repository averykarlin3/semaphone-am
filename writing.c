#include "sema.h"

int main() {
	int shkey = ftok(".averybadatdebugging", 3);
	int smkey = ftok(".averybadatdebugging", 4);
	int sem = semget(smkey, 1, 0644 | IPC_CREAT);
	if(sem < 0) {
		printf("Error: %s\n", strerror(errno));
	}
	struct sembuf enter;
	enter.sem_flg = SEM_UNDO;
	enter.sem_op = -1;
	enter.sem_num = 0;
	int check = semop(sem, &enter, 1);
	if(check < 0) {
		printf("Error: %s\n", strerror(errno));
	}
	int sh = shmget(shkey, sizeof(int), 0644);
	if(sh < 0)
		printf("Error: %s\n", strerror(errno));
	int f = open("story", O_RDONLY, 0644);
	if(f < 0)
		printf("Error: %s\n", strerror(errno));
	int* shn = shmat(sh, 0, 0);
	if(shn < 0)
		printf("Error: %s\n", strerror(errno));
	check = lseek(f, -1 * (*shn), SEEK_END);
	if(check < 0)
		printf("Error: %s\n", strerror(errno));
	char last[*shn];
	check = read(f, &last, *shn);
	if(check < 0)
		printf("Error: %s\n", strerror(errno));
	printf("%s\n", last);
	close(f);
	f = open("story", O_WRONLY | O_APPEND, 0644);
	char new[256];
	printf("New Line: ");
	fgets(new, sizeof(new), stdin);
	*shn = strlen(new); //Add one for null
	char * tempstr = new;
	check = write(f, tempstr, *shn);
	if(check < 0)
		printf("Error: %s\n", strerror(errno));
	close(f);
	shmdt(shn);
	enter.sem_op = 1;
	check = semop(sem, &enter, 1);
	if(check < 0)
		printf("Error: %s\n", strerror(errno));
	return 0;
}

