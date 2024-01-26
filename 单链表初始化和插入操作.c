#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode,*LinkList;
bool initlist(LinkList* L)//初始化链表
{
	*L = (LNode*)malloc(sizeof(LNode));//给头节点创建一块空间，使之可以访问下一个节点
	if (L == NULL)//判断是否创建成功
		return false;
	(*L)->next = NULL;//给链表的第一节点初始化为空指针，清除脏数据
		return true;
}
bool ListInsert(LinkList*L,int i,int e)
{
	if (i < 1)//判断是否在链表内，链表以一起始
		return false;
	int j = 0;
	LNode* p;
	p = (*L);//创建一个临时头节点进行寻找
	while (p != NULL && j < i - 1)//寻找要插入的前面的一个元素
	{
		p = p->next;
		j++;
	}
	if (p == NULL)//如果为NULL说明这个元素不存在
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));//如果找到就申请空间，再修改指向
	s->data = e;
	s->next = p->next;
	p->next = s;
}
int main()
{
	LinkList L;//用头节点创建一个链表
	initlist(&L);
	int i = 1, e = 4;
	ListInsert(&L, i, e);
	return 0;
}