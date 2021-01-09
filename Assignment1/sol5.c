#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
    pid_t ret;
    int status;
    ret=fork();
    if(ret< 0)
    {
        perror("fork");
        exit(1);
    }
    if(ret == 0)
    {
        int compile;
        compile = execl("/usr/bin/gcc","gcc","-g","sol1.c",NULL);  // Link and compile the file
        if(compile == 0)
        {
            perror("execv");
            exit(2);
        }
        exit(0);

    }
    else
    {
        waitpid(-1,&status,0); 
        printf("Exit status of parent--child = %d\n",
			WEXITSTATUS(status));
		
    }
    return 0;

}