#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main()
{
	//打开文件test.txt
	//相对路径
	//..表示上一级路径
	//.表示当前路径
	//fopen("..\..\test.txt","r");
	//fopen("test.txt","r");

	//绝对路径的写法,双斜杠是因为为了防止转义字符
	//fopen("E:\\编程代码\\Project2\\Project2\\test.txt", "r");

	//打开一个文件
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)				//打开成功返回一个指向FILE类型（文件信息区）的指针							
	{							//打开失败返回一个空指针
		printf("%s", strerror(errno));//打印错误信息
		return 0;
	}
	//打开成功
	//读文件

	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}