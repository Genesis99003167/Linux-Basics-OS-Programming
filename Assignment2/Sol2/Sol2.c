#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>

#define max_objects 10
#define buffer_size 10

sem_t empty;
sem_t full;
int IN = 0;
int OUT = 0;
int buffer[buffer_size];
//int true=1;

void* producer(void* p)
{
    sem_wait(&empty);
    for(int obj=0;obj<=max_objects;obj++){
    	while((IN+1) % buffer_size == OUT);
    	
        buffer[IN]=obj;
        printf("Producer has inserted object %d at %d\n",buffer[IN],IN);
        IN = (IN + 1)%buffer_size;
        
        sem_post(&full);    
    }
   
}
void* consumer(void* c)
{
    
    for(;;)
    {
    	sem_wait(&full);
        while( OUT == IN);
        int temp=buffer[OUT];
        printf("Consumer has removed object %d at %d\n",buffer[OUT],OUT);
        OUT  = (OUT + 1)%buffer_size;
        
    }
    sem_post(&empty);
  
    
}
int main()
{
    pthread_t p,c;
    sem_init(&empty,0,buffer_size);
    sem_init(&full,0,0);
    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);
    pthread_join(p,NULL);
    pthread_join(c,NULL);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}
