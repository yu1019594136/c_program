#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void event()
{
	unsigned int i,j;
	double y;
	for(i=0;i<1000;i++)
	{
		for(j=0;j<1000;j++)
		{
			y++;
		}
	}
}

void main()
{
	struct timeval tpstart,tpend;
	float timeuse;

	gettimeofday(&tpstart,NULL);
	event();
	sleep(5);//程序睡眠5秒
	usleep(500);//程序睡眠5微秒
	gettimeofday(&tpend,NULL);

	timeuse=1000000*(tpend.tv_sec-tpstart.tv_sec)+tpend.tv_usec-tpstart.tv_usec;
	//timeuse/=1000000;

	printf("this evevt cost %f us.\n",timeuse);
	exit(0);
}
