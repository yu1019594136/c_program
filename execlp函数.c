#include <unistd.h>
int main()
{
	execlp("ls","ls","-al","/etc/passwd",NULL);
//��һ��ls��ʾ�����ļ������ڶ���ls��ʾ�������ƣ�
}