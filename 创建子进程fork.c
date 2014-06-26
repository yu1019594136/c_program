#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	pid_t pid;
	/*��ʱ����һ������*/
	pid=fork();

	/*��ʱ����������*/
	if(pid<0)
		printf("error in the fork !\n");
	else if(pid == 0)
		printf("I am the child process, ID is %d.\n",getpid());
	else
		printf("I am the parent process, ID is %d. my child process's ID is %d.\n",getpid(),pid);
}