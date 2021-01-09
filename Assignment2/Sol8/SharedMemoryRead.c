#include "SharedMemory.h"

int main()
{
	int filesize=4096; 
	int fd,offsetvalue=0;
	fd=shm_open("/shm1",O_CREAT|O_RDWR,0666);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
        ftruncate(fd, filesize);
	void *pbaseval;
	pbaseval=mmap(0,filesize, PROT_READ, MAP_SHARED,fd,offsetvalue);
	if(pbaseval==MAP_FAILED)
	{
		fprintf(stderr,"mapping failed\n");
		exit(1);
	}
	sem_t *ps,*qs;
	ps=sem_open("/s1",O_CREAT, 0777, 1);
	qs=sem_open("/s2",O_CREAT, 0777, 0);
	char buffervalue[64];
	sem_wait(qs);
	sem_wait(ps);
        strncpy(buffervalue,pbaseval,14);
	printf("buf=%s\n",buffervalue);
	
	sem_post(ps);
	sem_unlink("s1");
	sem_unlink("s2");
	munmap(pbaseval,filesize);
	return 0;
}
