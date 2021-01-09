#include "ClientServer.h"

int main()
{
	int ret1,bytes1;
	mqd_t mqid2;
	
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqid2=mq_open("/mque2",O_RDONLY|O_CREAT,0666,&attr);  // Open message queue in Client 
	
	if(mqid2<0)
	{
		perror("mq_open");
		exit(1);
	}
	
	char buffer1[8192];
	int max_length=256,priority;
	bytes1=mq_receive(mqid2,buffer1,max_length,&priority); // Receive message from Server through message queue
	if(bytes1<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buffer1[bytes1]='\0';
	printf("%s",buffer1);
	//int q;
	int q=execlp("/usr/bin/cal","cal",buffer1,0);
        if(q<0)
		{
			perror("execlp");
			exit(1);
		}
		exit(5);
		
	printf("Receive messaged from Server is :%s,nbytes=%d,priority=%d\n",buffer1,bytes1,priority);
	

	
	mq_close(mqid2);
	return 0;
}
