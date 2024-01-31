#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct S
{
	int a;
	float b;
	char arr[10];
};
int main()
{
	struct S s = { 100,3.14,"abcdef" };
	char tmp[1024] = {0};
	struct S tmp2 = { 0 };
	//把格式化的数据存储到字符串
	sprintf(tmp, "%d %f %s", s.a, s.b, s.arr);
	printf("%s\n", tmp);
	//从字符串中读取格式化的数据
	sscanf(tmp, "%d %f %s", &(tmp2.a), &(tmp2.b), tmp2.arr);
	printf("%d %f %s", tmp2.a,tmp2.b,tmp2.arr);
	return 0;
}