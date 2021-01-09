#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    
    FILE* file1;
    int count_lines=0,count_charecters=0,count_words=0;
    char ch;
    file1=fopen("Results.txt","r");
    printf("\nReturn value of file open = %d\n",file1);
    if(file1<0)
    {
        perror("file open");
        exit(1);
    }
    while((ch=fgetc(file1))!=EOF)
    {
        count_charecters++;
        if(ch=='\n'||ch=='\0')
        {
            count_lines++;
        }
        if(ch==' '||ch=='\t'||ch=='\n'||ch=='\0')
        {
            count_words++;
        }
        
    }
    printf(" No. of characters is %d",count_charecters);
    printf(" No. of words is %d",count_words);
    printf(" No. of lines is %d",count_lines);
    fclose(file1);
    return 0;
}
