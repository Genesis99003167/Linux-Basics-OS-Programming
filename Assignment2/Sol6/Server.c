#include "ClientServer.h"

int main()
{
	int ret,nbytes;
	struct mq_attr attr;
	struct stat sb;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqd_t mqid;
	
	mqid=mq_open("/mque",O_CREAT | O_RDWR,0666,&attr);  // Open a Message Queue in Server Process
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}

	char buffer[20];
	int maxlen=256,priority;
	
	printf("Waiting for message from Client \n");  // Receive a message from Queue
	nbytes=mq_receive(mqid,buffer,1024,&priority);
	if(nbytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	
	lstat(buffer, &sb);  // Getting file attributes
	
	ret = mq_send(mqid,(const char *)&sb,sizeof(sb),100);  // Send back the attributes message to Client through Queue
	if(ret < 0)
	{
		perror("mq_send");
		exit(2);
	}
	
	mq_close(mqid);  // Close the Queue 
	return 0;
}
