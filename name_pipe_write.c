#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FIFO_SERVER "/home/zhouyu/myfifo"

int main(int argc, char **argv)
{
	int fd;
	char w_buf[100];
	int n_write;
	
	if(argc==1)//参数检查 
	{
		printf("please send something!\n");
		exit(-1);
	}
	/*打开管道*/
	fd=open(FIFO_SERVER,O_WRONLY|O_NONBLOCK);
	
	if(fd==-1)
	{
		printf("pipe open failed !");
		exit(-1);
	}
	
	strcpy(w_buf,argv[1]);
	
	/*向管道写入数据*/
	if((n_write=write(fd,w_buf,100))==-1)
	{
	 	if(errno == EAGAIN)
			printf("the FIFO has not been read yet. please try later\n");
	}
	else 
		printf("write %s to the FIFO\n",w_buf);
	
	return 0;  
}
