#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 && p2);
	char* s1, * s2;
	char* cur = p1;
	if (!*p2)
		return  (char*)p1;
	while (*cur)
	{
		s1 = cur;
		s2 = p2;
		while (*s1 && *s2 && !(*s1 - *s2))
		{
			s1++;
			s2++;
		}
		if (!*s2)
			return (char*)cur;
		cur++;
	}
	return NULL;
}
int main()
{
	char* p1 = "abbbbcdef";
	char* p2 = "bcd";
	char* ret = my_strstr(p1, p2);
	printf("%s", ret);
	return 0;
}