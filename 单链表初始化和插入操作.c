#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode,*LinkList;
bool initlist(LinkList* L)//��ʼ������
{
	*L = (LNode*)malloc(sizeof(LNode));//��ͷ�ڵ㴴��һ��ռ䣬ʹ֮���Է�����һ���ڵ�
	if (L == NULL)//�ж��Ƿ񴴽��ɹ�
		return false;
	(*L)->next = NULL;//������ĵ�һ�ڵ��ʼ��Ϊ��ָ�룬���������
		return true;
}
bool ListInsert(LinkList*L,int i,int e)
{
	if (i < 1)//�ж��Ƿ��������ڣ�������һ��ʼ
		return false;
	int j = 0;
	LNode* p;
	p = (*L);//����һ����ʱͷ�ڵ����Ѱ��
	while (p != NULL && j < i - 1)//Ѱ��Ҫ�����ǰ���һ��Ԫ��
	{
		p = p->next;
		j++;
	}
	if (p == NULL)//���ΪNULL˵�����Ԫ�ز�����
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));//����ҵ�������ռ䣬���޸�ָ��
	s->data = e;
	s->next = p->next;
	p->next = s;
}
int main()
{
	LinkList L;//��ͷ�ڵ㴴��һ������
	initlist(&L);
	int i = 1, e = 4;
	ListInsert(&L, i, e);
	return 0;
}