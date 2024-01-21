#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
void* my_memmove(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	if (dest < src)
	{
		//前-->后
		while (num--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest, ++(char*)src;
		}
	}
	else
	{
		//后-->前
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return ret;
}
int main()
{
	int arr[20] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr+4, arr, 20);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}