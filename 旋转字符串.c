#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void left_move(char *arr,int k)
{
	for(int i=0;i<k;++i)
	{
		char tmp = *arr;
		int j = 0;
		for (j = 0; arr[j] != '\0'; ++j)
		{
			*(arr + j) = *(arr + j + 1);
		}
		arr[j - 1] = tmp;
	}
}
int main()
{
	char arr[] = "ABCDEF";
	int k=0;
	scanf("%d", &k);
	left_move(arr,k);
	printf("%s", arr);
	return 0;
}