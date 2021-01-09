#include "ClientServer.h"


int main() {
  int ret, nbytes;
  mqd_t mqid;
  struct mq_attr attr;
  struct stat sb;
  attr.mq_msgsize = 256;
  attr.mq_maxmsg = 10;
  
  mqid = mq_open("/mque", O_CREAT | O_RDWR, 0666, &attr); // Open a Message Queue in Client Process
  if (mqid < 0) {
    perror("mq_open");
    exit(1);
  }

  char str[20] = "hello.c";
  ret = mq_send(mqid, str, 20, 5);  // Send file name to Server
  if (ret < 0) {
    perror("mq_send");
    exit(2);
  }

  int maxlen = 256, priority;

  nbytes = mq_receive(mqid, (char *)&sb, 1024, &priority);  // Receive the message from Server through Queue
  if (nbytes < 0) {
    perror("mq_recv");
    exit(2);
  }

 
  printf("----------------File Attributes----------------\n");  // Print the file attributes
  printf("ID of device containing file    : %ld\n", (long)sb.st_dev);
  printf("Inode number                    : %ld\n", (long)sb.st_ino);
  printf("File type                       : ");
  switch (sb.st_mode & S_IFMT) {
  case S_IFBLK:
    printf("block device\n");
    break;
  case S_IFCHR:
    printf("character device\n");
    break;
  case S_IFDIR:
    printf("directory\n");
    break;
  case S_IFIFO:
    printf("FIFO/pipe\n");
    break;
  case S_IFLNK:
    printf("symlink\n");
    break;
  case S_IFREG:
    printf("regular file\n");
    break;
  case S_IFSOCK:
    printf("socket\n");
    break;
  default:
    printf("unknown?\n");
    break;
  }
  printf("Mode                            : %lo (octal)\n", (unsigned long)sb.st_mode);
  printf("Link count                      : %ld\n", (long)sb.st_nlink);
  printf("User ID                         : %ld\n" , (long)sb.st_uid);
  printf("Group ID                        : %ld\n", (long)sb.st_gid);
  printf("Blocksize for file system I/O   : %ld bytes\n", (long)sb.st_blksize);
  printf("File size                       : %lld bytes\n", (long long)sb.st_size);
  printf("Number of 512B Blocks allocated : %lld\n", (long long)sb.st_blocks);
  printf("Last status change              : %s", ctime(&sb.st_ctime));
  printf("Last file access                : %s", ctime(&sb.st_atime));
  printf("Last file modification          : %s", ctime(&sb.st_mtime));

 
  mq_close(mqid);  // Close the Queue 

  return 0;
}
