#include<unistd.h>
#include<stdio.h> 
#include<fcntl.h>
#include<string.h> 
#include<stdlib.h> 
void main() 
{
    char str[256]="I'm learning IPCs"; 
    int fifo_write,fifo_read; 
    while(strcmp(str,"end")!=0)   
    {   
        fifo_write= open("pipe1",O_WRONLY);   
        if(fifo_write<0)     
            printf("\nError opening pipe");   
        else     
        {     
            printf("Chat 2: %s",str);     
            scanf("%s",str);     
            write(fifo_write,str,255*sizeof(char));     
            close(fifo_write);     
        }   
        fifo_read=open("pipe2",O_RDONLY);   
        if(fifo_read<0)     
            printf("\nError opening write pipe");   
        else     
        {     
            read(fifo_read,str,255*sizeof(char));     
            close(fifo_read);     
            printf("\n%s",str);     
        }   
    }
}
