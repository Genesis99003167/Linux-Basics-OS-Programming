
#include<unistd.h>
#include<stdio.h> 
#include<fcntl.h>
#include<string.h> 
#include<stdlib.h> 
void main() 
{
    int fifo1;
    fifo1 = mkfifo("pipe1",0666);
    if(fifo1<0)
        printf("\npipe1 was not created");
    else
        printf("\npipe1 is created");
    int fifo2;
    fifo2 = mkfifo("pipe2",0666);
    if(fifo2<0)
        printf("\npipe2 was not created");
    else
        printf("\npipe2 is created\n");
}
