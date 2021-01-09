#include "SharedMemory.h"


int main()
{
	int filesize=4096; 
	int fd,offsetvalue=0;
	sem_t *ps,*qs;
	ps=sem_open("/s1",O_CREAT, 0777, 1);
	qs=sem_open("/s2",O_CREAT, 0777, 0);
	fd=shm_open("/shm1",O_CREAT|O_RDWR,0666);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
       ftruncate(fd, filesize);
	void *pbaseval;
	pbaseval=mmap(0,filesize, PROT_WRITE, MAP_SHARED,fd,offsetvalue);
	if(pbaseval==MAP_FAILED)
	{
		fprintf(stderr,"mapping failed\n");
		exit(1);
	}
	 char bufferval[64];
        char input[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        sem_wait(ps);
	strncpy(pbaseval,input,10);	
	sem_post(ps);
	sem_post(qs);
	printf("buffervalue=%s\n",input);
	munmap(pbaseval,filesize);
	return 0;
}

