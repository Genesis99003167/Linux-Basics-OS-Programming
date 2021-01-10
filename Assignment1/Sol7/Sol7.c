#include "Sol7.h"

void* sum_func(void* sub_array)
{
    int* array_part = (int*)sub_array;
    int sum=0;
    for(int i=0;i<10;i++)
    {
        sum+=array_part[i];
    }
    pthread_exit((void*)sum);

}
int main()
{
    int array[1000];
    int sum_final=0;
    void* sum;
    for(int i=0;i<=100;i++)  // Declaring a array from 0 to 99
    {
        array[i]=i;
    }
    pthread_t threads[10];  // Create 10 threads of arrays of size 100
    for(int i=0;i<10;i++)
    {
        int* sub_array=array + (i*10);
        pthread_create(&threads[i],NULL,sum_func,(void*) sub_array);
    }
    for(int i=0;i<10;i++)
    {
        pthread_join(threads[i],&sum);  // Join the 10 threads to get the final thread array of size 100
        sum_final+=(int)sum;
    }
    printf("total = %d\n",sum_final);
    return 0;
}
