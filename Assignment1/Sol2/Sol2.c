#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE* fd;
    char ch;
    int words_count=0;
    int characters_count=0;
    int lines_count=0;
    fd=fopen("Results.txt",O_RDONLY);
    if(fd<0)
    {
	perror("open");
	exit(1);
    }
    for (ch = fgetc(fd); ch != EOF; ch = fgetc(fd)) 
    {
        characters_count++;
        if (ch == '\n') // Increment count if this character is newline 
            lines_count++;
        if (ch == ' ' | ch == ',')
            words_count++;
    }
    printf("No. of characters = %d,No. of words = %d,No.of lines = %d",characters_count,words_count,lines_count);
    fclose(fd) ;
    return 0;   
}
