#include "SemaphoreStack.h"

#define max_objects 10
#define buffer_size 10

sem_t empty;
sem_t full;
int IN = 0;
int OUT = 0;
int buffer[buffer_size];

void* producer(void* pro)
{
    
    
    sem_wait(&empty);
    for(int IN=0;IN<max_objects;IN++){
    	int obj=rand();
        buffer[IN]=obj;
        printf("Producer has inserted object %d at %d\n",buffer[IN],IN);
            
    }
    IN = (IN + 1)%buffer_size;
    sem_post(&full);
    
}
void* consumer(void* con)
{
    
    sem_wait(&full);
    
    for(int OUT=0;OUT<max_objects;OUT++)
    {
        
        int obj=buffer[OUT];
        printf("Consumer has removed object %d at %d\n",buffer[OUT],OUT);
    }
        
    OUT  = (OUT + 1)%buffer_size;
    sem_post(&empty);
    
}
int main()
{
    pthread_t pro,con;
    sem_init(&empty,0,buffer_size);
    sem_init(&full,0,0);
    pthread_create(&pro,NULL,producer,NULL);
    pthread_create(&con,NULL,consumer,NULL);
    pthread_join(pro,NULL);
    pthread_join(con,NULL);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}
