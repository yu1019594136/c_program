#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	pid_t pc,pr;
	pc=fork();
	if(pc==0)//如果是子进程
	{
		printf("this is the child process with pid of %d.\n",getpid());
		printf("i want to sleep for 10 seconds.\n");
		sleep(10);
		printf("i wake up.\n");
	}
	else if(pc>0)//如果是父进程
	{
	pr=wait(NULL);
	printf("I catched a child process with pid of %d.\n",pr);
	}
	exit(0);
}