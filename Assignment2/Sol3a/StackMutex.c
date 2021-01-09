#include "StackMutex.h"

#define max_objects 10
#define buffer_size 10


int IN = 0;
int OUT = 0;
int buffer[buffer_size];
pthread_mutex_t mutex;

void* producer(void* p)
{
    if(IN == buffer_size -1)
    {
    	printf(" PRODUCER OBJECTS STACK IS FULL\n");
    }
    else
    {
    
    pthread_mutex_lock(&mutex);
    
    for(int IN=0;IN<max_objects;IN++)
    {
    	int obj=rand();
        buffer[IN]=obj;
        printf("Producer has inserted object %d at %d\n",buffer[IN],IN);     
    }
    IN = (IN + 1)%buffer_size;
    pthread_mutex_unlock(&mutex);
   
    }
    
}
void* consumer(void* c)
{
    if(IN == buffer_size -1)
    {
    	printf(" CONSUMER OBJECTS STACK IS EMPTY\n");
    }
    else
    {
    pthread_mutex_lock(&mutex);
    
    for(int OUT=0;OUT<max_objects;OUT++)
    {
        
        int obj=buffer[OUT];
        printf("Consumer has removed object %d at %d\n",buffer[OUT],OUT);
    }
        
    OUT  = (OUT + 1)%buffer_size;
    pthread_mutex_unlock(&mutex);
    }
}
int main()
{
    pthread_t p,c;
    pthread_mutex_init(&mutex,NULL);
    
    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);
    pthread_join(p,NULL);
    pthread_join(c,NULL);
    pthread_mutex_destroy(&mutex);
    
    return 0;
}
