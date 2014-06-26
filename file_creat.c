#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void creat_file(char *filename)
{
	if(creat(filename,0755)<0)
	{
		printf("creat file %s failure ! \n",filename);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("creat file %s success ! \n",filename);
	}
}

int main(int argc, char *argv[])
{
	int i;
	if(argc<2)
	{
		perror("you haven't input the filename, please try again !");
		exit(EXIT_FAILURE);
	}
	for(i=1;i<argc;i++)
	{
		creat_file(argv[i]);
	}
	exit(EXIT_SUCCESS);
}