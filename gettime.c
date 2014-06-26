#include <stdio.h>
#include <time.h>
int main()
{
	struct tm *gm,*local;
	time_t t;/*typedef long time_t*/
	t=time(NULL);//获取日历时间
	local=localtime(&t);//将日历时间转化为本地时间，保存至tm结构

	printf("当前本地时间为%s.\n\n\n",ctime(&t));//将日历时间转化成本地时间的字符串格式

	printf("sizeof(local) = %d\n",sizeof(local));
	printf("当前本地时间为：%s\n",asctime(local));//该函数将tm结构体转化成字符串形式
	
	printf("%d\n",local->tm_sec);
	printf("%d\n",local->tm_min);
	printf("%d\n",local->tm_hour);
	printf("%d\n",local->tm_mday);
	printf("%d\n",local->tm_mon);
	printf("%d\n",local->tm_year+1900);
	printf("%d\n",local->tm_wday);
	printf("%d\n",local->tm_yday);
	
	gm=gmtime(&t);//将日历时间转化为格林威治时间，保存至tm结构
	printf("sizeof(gm) = %d\n",sizeof(gm));
	printf("当前格林威治时间为：%s\n",asctime(gm));
	printf("%d\n",gm->tm_sec);
	printf("%d\n",gm->tm_min);
	printf("%d\n",gm->tm_hour);
	printf("%d\n",gm->tm_mday);
	printf("%d\n",gm->tm_mon);
	printf("%d\n",gm->tm_year+1900);
	printf("%d\n",gm->tm_wday);
	printf("%d\n",gm->tm_yday);

	return 0;
}
