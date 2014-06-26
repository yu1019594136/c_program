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

	//���flag����������o_creat�����ļ�������ʱ�������Զ��������ļ�����ʱ�����������������
	//���û��o_creat�����������������Ҫ����ʱ���Ҫ�򿪵��ļ������ڣ��򱨴�
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
