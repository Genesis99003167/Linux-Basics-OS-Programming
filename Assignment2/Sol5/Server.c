#include "ClientServer.h"

int main()
{
	int ret1;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqd_t mqid2;
	
	mqid2 = mq_open("/mque2",O_WRONLY|O_CREAT,0666,&attr);  // Open message queue in Server
	
	if(mqid2<0)
	{
		perror("mq_open");
		exit(1);
	}
	char value[]="2021";
	int length=strlen(value);
	ret1=mq_send(mqid2,value,length+1,5);
	if(ret1<0)
	{
		perror("mq_send");
		exit(2);
	}
	printf("Received Message of Client and executed in child process using execlp");
	mq_close(mqid2);
	return 0;
}
