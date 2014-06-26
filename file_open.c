#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd;
	if(argc<2)
	{
		perror("please input the open pathname !\n");
		exit(EXIT_FAILURE);
	}

	//如果flag参数里面有o_creat，该文件不存在时，程序将自动创建该文件，此时必须给出第三个参数
	//如果没有o_creat，则第三个参数不需要，此时如果要打开的文件不存在，则报错。
	if((fd=open(argv[1],O_CREAT|O_RDWR,0755))<0)
	{
		perror("open file failure !\n");
		exit(1);
	}
	else
	{
		printf("open file %s success!\n",argv[1]);
	}
	printf("file %s close !\n",argv[1]);
	close(fd);
	exit(0);
}
