#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int ElemType;//�������κ�����Ԫ��
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
bool initlist(LinkList* L)//��ʼ������
{
	*L = (LNode*)malloc(sizeof(LNode));//��ͷָ�봴��һ��ռ䣬ʹ֮���Է�����һ���ڵ�
	if (L == NULL)//�ж��Ƿ񴴽��ɹ�
		return false;
	(*L)->next = NULL;//������ĵ�һ�ڵ��ʼ��Ϊ��ָ�룬���������
		return true;
}
bool InsertNextNode(LNode* p, ElemType e)//����������ָ���ڵ���������
//��������޸ĵĲ�����p������p��ָ��Ŀռ䣬��˲��ô�p�ĵ�ַ
{
	if (p == NULL)//���ΪNULL���޷�����
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));//����ҵ�������ռ䣬���޸�ָ��
	if (s == NULL)
		return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
bool InsertPriorNode(LNode* p, ElemType e)//ǰ�����
//ֻ�Ƕ�p��ָ��Ŀռ����޸ģ�û�ж�p�������κ��޸�
{
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->next = p->next;
	p->next = s;
	s->data = p->data;
	p->data = e;
	return true;
}
bool DeleteNode(LNode* p)//ɾ��ָ���ڵ�
{
	if (p == NULL)//����һ�������е���ʱ���ܻ����p==NULL�����������жϺ��б�Ҫ
		return false;
	LNode* q = p->next;
	if (q == NULL)
	{
		free(q);
		p = NULL;
		return true;
	}
	q->data = p->data;
	p->next=q->next;
	free(q);
	return true;
}
LNode* LocateElem(LinkList L, ElemType e)//��ֵ����
{
	LNode* p = L->next ;//�ӵ�һ��ֵ��ʼ����
	while (p != NULL && p->data != e)
		p = p->next;
	return p;//�ҵ����ظ�ָ�룬�Ҳ�������p
}
bool ListDelete(LinkList* L, int i, ElemType* e)//ɾ��ָ��λ�õĽڵ�
//��ʱ�����ɻ����L����Ҳ���Ը�
//��ʵ����Ǵ�L����ȷʵ�����ҵ��ǿ�ռ䲢�޸ģ��������߳�����ʱ�Ƿ���ʱ�����ᱻ�ͷŵ�
{
	if (i < 1)
		return false;
	int j = 0;
	LNode* p = *L;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)//iֵ���Ϸ�
		return false;
	if (p->next == NULL)//i-1������û�������ڵ�
		return false;
	LNode* q = p->next;
	*e = q->data;
	p->next = q->next;
	free(q);
	return true;
}
bool ListInsert(LinkList*L,int i,ElemType e)//��ָ��λ�ò��루��ͷ�ڵ㣩
//�����Դ�L���������L�������һ����ʱ�������޷��ں����ڲ��޸���
//����L�ĵ�ַ�������޸ľͿ��Ըı�ԭ�������ֵ
//LinkList�������������������������������ı䣬���Ҫ��������ĵ�ַ
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
	return InsertNextNode(p, e);
}

int main()
{
	//��ͷָ�봴��һ������L��ָ��ͷ�ڵ��
	LinkList L;//LinkList��������������
	initlist(&L);
	int i = 1, e = 4;
	ListInsert(&L, i, e);
	return 0;
}