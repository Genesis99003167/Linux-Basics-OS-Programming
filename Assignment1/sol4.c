#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
    pid_t ret_value;
    int status;
    int cmd_exec;
    char CLIin[10];
    //printf("Enter your path:"); 
    //scanf("%s", input1); 
    printf("Enter the command:");
    scanf("%s", CLIin); 
                 
    ret_value=fork();
    
    if(ret_value<0)
    {
        perror("fork");
        exit(1);
    }
    if(ret_value==0)
    {
        cmd_exec=execlp(CLIin,CLIin,NULL);
        if(cmd_exec<0)
        {
            perror("execlp");
            exit(2);
        }
        exit(0);
    }
    else
    {
        waitpid(-1,&status,0); 
        //wait(&status);
        printf("Exit status of parent--child = %d\n",
			WEXITSTATUS(status));
    }
}