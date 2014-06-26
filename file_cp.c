#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
	int fd_from,fd_to;//
	int file_access=0;//
	int byte_read,byte_write;
	int i=0;
	char file_buf[BUFFER_SIZE];
	char *ptr;
	
	
	if(argc!=3)//
	{
		printf("An incorrect input ! please check the parameter.\n");
		exit(EXIT_FAILURE);
	}

	if(access(argv[1],F_OK))//
	{
		printf("there is no file %s !\n",argv[1]);
		exit(EXIT_FAILURE);
	}

	if(access(argv[1],R_OK))//
	{
		printf("you have no read permission to file %s !\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	else
	{
		file_access+=4;
	}
	
	if(access(argv[1],W_OK)==0)//
	{
		file_access+=2;
	}

	if(access(argv[1],X_OK)==0)//
	{
		file_access+=1;
	}

	
	if((fd_from=open(argv[1],O_RDONLY))<0)
	{
		printf("you can't open the file %s !\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	

	if(file_access==5)
	{
		if((fd_to=creat(argv[2],0555))<0)
		{
			printf("creat file %s failure ! \n",argv[2]);
			close(fd_from);
			exit(EXIT_FAILURE);
		}
	}
	else if(file_access==6)
	{
		if((fd_to=creat(argv[2],0655))<0)
		{
			printf("creat file %s failure ! \n",argv[2]);
			close(fd_from);
			exit(EXIT_FAILURE);
		}
	}
	else if(file_access==7)
	{
		if((fd_to=creat(argv[2],0755))<0)
		{
			printf("creat file %s failure ! \n",argv[2]);
			close(fd_from);
			exit(EXIT_FAILURE);
		}
	}
	
	while(byte_read=read(fd_from,file_buf,BUFFER_SIZE))
	{
		if(byte_read==-1)
		{
			printf("复制时源文件读取发生错误！\n");
			break;
		}
		else if(byte_read>0)
		{
			ptr=file_buf;
			while(byte_write=write(fd_to,ptr,byte_read))
			{
				if(byte_write==-1)
				{
					printf("复制时目标文件写入发生错误！\n");
					break;
				}
				else if(byte_read==byte_write)
				{
					break;
				}
				else if(byte_write>0)
				{
					ptr+=byte_write;
					byte_read-=byte_write;
				}
			}
			if(byte_write==-1)
			break;
		}
	}
	close(fd_from);
	close(fd_to);
	exit(0);
}
