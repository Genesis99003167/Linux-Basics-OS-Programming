#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
    pid_t child1,child2,child3;
    int exec_1,exec_2,exec_3;
    child1=fork();
    switch(child1)
    {
    	case(-1):
    	{
        	perror("fork");
        	exit(1);
        }
        case(0):
        {
        	exec_1 = execl("/usr/bin/gcc","gcc","-c","test.c","sub_cube.c",NULL);
        	if(exec_1<1)
        	{
            		perror("execl");
            		exit(2);
        	}
        	break;
        }
        default:
        {
        	waitpid(-1,0,0);
        	printf("Successful Compilation\n");
        	child2=fork();
        	break;
        }
     }
     
    switch(child2)
    {
    case(-1):
        perror("fork");
        exit(1);
    case(0):
        exec_3 = execl("/usr/bin/gcc","gcc","test.o","sub_cube.o",NULL);
        if(exec_3 < 1)
        {
            perror("execl");
            exit(2);
        }
        break;
    default:
        waitpid(-1,0,0);
        printf("Successful library link established\n");
        child3=fork();
        break;

    }
    switch(child3)
    {
    case(-1):
        perror("fork");
        exit(1);
    case(0):
        
        exec_2 = execl("./a.out",NULL);
        if(exec_2<1)
        {
            perror("execl");
            exit(2);
        }
        break;
    default:
        waitpid(-1,0,0);
        printf("Successful Execution\n");
        break;
    }
}
