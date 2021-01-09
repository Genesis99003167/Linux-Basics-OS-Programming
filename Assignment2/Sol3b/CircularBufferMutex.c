#include "CircularBufferMutex.h"

#define max_objects 10
#define buffer_size 10


int IN = 0;
int OUT = 0;
int buffer[buffer_size];
pthread_mutex_t mutex;

void* producer(void* p)
{ 
    //pthread_mutex_lock(&mutex);
    int obj;
    
    
    
    for(int i=0;i<=max_objects;i++)
    {
       pthread_mutex_lock(&mutex);
    	while((IN+1) % buffer_size == OUT)
    	{
    	
          buffer[IN]=obj;
          printf("Producer has inserted object %d at %d\n",buffer[IN],IN);
          IN = (IN + 1)%buffer_size;
        }
        
       pthread_mutex_unlock(&mutex);     
    }
    //pthread_mutex_unlock(&mutex); 
   
}
void* consumer(void* c)
{
    int obj;
    
    //for(int i=0;i<max_objects;i++)
    for(;;)
    {
     pthread_mutex_unlock(&mutex);	
        while( OUT == IN)
        {
        obj=buffer[OUT];
        printf("Consumer has removed object %d at %d\n",buffer[OUT],OUT);
        OUT  = (OUT + 1)%buffer_size;
        }
     pthread_mutex_lock(&mutex);      
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
