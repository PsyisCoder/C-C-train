#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void move(int arr[],int sz)
{
	int left = 0;
	int right = sz-1;
	//´ÓÓÒ±ßÕÒÆæÊý
	while(left<right)
	{
		while ((left < right) && (arr[right] % 2 == 0))
		{
			right--;
		}
		while ((left < right) && (arr[left] % 2 == 1))
		{
			left++;
		}
		if(left<right)
		{
			int tmp;
			tmp = arr[right];
			arr[right] = arr[left];
			arr[left] = tmp;
		}
	}
	
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	move(arr,sz);
	print(arr,sz);
	return 0;
}