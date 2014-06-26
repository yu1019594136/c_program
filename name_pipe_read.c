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
	char r_buf[100];
	int n_read;
	
	/*创建命名管道*/
	if(mkfifo(FIFO_SERVER,O_CREAT|O_EXCL)<0 && (errno!=EEXIST))
		printf("can not create fifoserver.!\n");

	printf("preparing for reading bytes ....\n");
	
	memset(r_buf,0,sizeof(r_buf));//初始化内存空间

	/*打开管道*/
	fd=open(FIFO_SERVER,O_RDONLY|O_NONBLOCK,0);
	
	if(fd==-1)
	{
		printf("pipe open failed !\n");
		perror("open");
		exit(1);
	}
	
	while(1)
	{
		memset(r_buf,0,sizeof(r_buf));//初始化内存空间
		if((n_read=read(fd,r_buf,100))==-1)
		{
			if(errno==EAGAIN)
				printf("no data yet.\n");
		}
		printf("read %s from FIFO.\n",r_buf);
		sleep(1);
	}
	pause();//暂停，等待信号
}
