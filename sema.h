#ifndef SEMA_H
#define SEMA_H 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>


#if ! defined(__FreeBSD__) && ! defined(__OpenBSD__) && \
                ! defined(__sgi) && ! defined(__APPLE__)  //I took this from http://man7.org/tlpi/code/online/dist/svsem/semun.h.html

union semun {
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *__buf;
};

#endif


#endif
