#include "Sol1.h"

int main()
{
    int file1,size_buffer;
	file1 =open("Results.txt",O_RDONLY);  // Open file1 for reading
    printf("\nReturn value of file1=%d\n",file1);
	if(file1<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen=300;
	char buffer[maxlen];
	size_buffer=read(file1,buffer,maxlen);
	if(size_buffer<0)
	{
		perror("read");
		exit(2);
	}
    printf("size_buffer=%d\n,buffer=%s\n",size_buffer,buffer);
    int file2, size_file;
	file2 = open("sample.txt",O_WRONLY|O_CREAT, 0666);  // Open file2 for writing
	if(file2<0)
	{
		perror("open");
		exit(3);
	}
	size_file =	write(file2, buffer, maxlen);  // Copying file1 to file2
    if(size_file<0)
	{
		perror("write");
		exit(4);
	}
    close(file1);
    close(file2);
    printf("Copy Successful \n");  
}
