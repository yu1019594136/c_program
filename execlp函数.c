#include <unistd.h>
int main()
{
	execlp("ls","ls","-al","/etc/passwd",NULL);
//第一个ls表示程序文件名，第二个ls表示命令名称，
}