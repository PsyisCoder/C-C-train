#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//struct S
//{
//	int n;
//	int arr[0];
//};
struct S
{
	int n;
	int* arr;
};
int main()
{
	/*struct S* p = (struct S*)malloc(sizeof(struct S) + 10 * sizeof(int));
	p->n = 100;
	for(int i=0;i<10;++i)
	{
		p->arr[i]=i;
	}
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", p->arr[i]);
	}
	free(p);
	p = NULL;*/
	struct S* p = (struct S*)malloc(sizeof(struct S));
	p->arr = (int*)malloc(10 * sizeof(int));
	p->n = 100;
	for (int i = 0; i < 10; ++i)
	{
		p->arr[i] = i;
	}
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", p->arr[i]);
	}
	printf("\n");
	int* s = (int*)realloc(p->arr, 20 * sizeof(int));
	for (int i = 0; i < 20; ++i)
	{
		p->arr[i] = i;
	}
	for (int i = 0; i < 20; ++i)
	{
		printf("%d ", p->arr[i]);
	}
	free(p->arr);
	p->arr = NULL;
	free(p);
	p = NULL;
	return 0;
}