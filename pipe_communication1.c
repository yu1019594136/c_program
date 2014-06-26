#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
/*必须在系统调用fork()之前调用pipe(),否则子进程将不会继承文件描述符。*/
int main()
{
	int pipe_fd[2];
	pid_t pid;
	int r_num,w_num;
	char buf_r[100];
	char *p_buf_r;
	
	
	
	
	if(pipe(pipe_fd)<0)
	{
		printf("pipe create fail !\n");
		return -1;
	}
	else
	{
		printf("pipe create success !\n");
		printf("pipe_fd[0] = %d.\n",pipe_fd[0]);
		printf("pipe_fd[1] = %d.\n",pipe_fd[1]);
	}

	pid=fork();
	if(pid==0)//子进程
	{
		printf("\n");
		close(pipe_fd[1]);
		sleep(2);/*给时间给父进程写入数据*/
		if((r_num=read(pipe_fd[0],buf_r,100))>0)
		{
			printf("%d characters read from the pipe is %s \n",r_num,buf_r);
		}
		close(pipe_fd[0]);
		exit(0);
	}
	else if(pid>0)//父进程
	{
		close(pipe_fd[0]);
		if((w_num=write(pipe_fd[1],"hello",5))!=-1)
			printf("parent write hello 6 ! w_num = %d \n",w_num);
		if(write(pipe_fd[1],"pipe",4)!=-1)
			printf("parent write pipe 5 ! w_num = %d \n",w_num);
		close(pipe_fd[1]);
		sleep(3);
		waitpid(pid,NULL,0);//等待子进程结束
		exit(0);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	
	return 0;
}
