#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int ElemType;//可以是任何类型元素
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
bool initlist(LinkList* L)//初始化链表
{
	*L = (LNode*)malloc(sizeof(LNode));//给头指针创建一块空间，使之可以访问下一个节点
	if (L == NULL)//判断是否创建成功
		return false;
	(*L)->next = NULL;//给链表的第一节点初始化为空指针，清除脏数据
		return true;
}
bool InsertNextNode(LNode* p, ElemType e)//后插操作，在指定节点后插入数据
//这个函数修改的并不是p，而是p所指向的空间，因此不用传p的地址
{
	if (p == NULL)//如果为NULL则无法插入
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));//如果找到就申请空间，再修改指向
	if (s == NULL)
		return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
bool InsertPriorNode(LNode* p, ElemType e)//前插操作
//只是对p所指向的空间做修改，没有对p本身作任何修改
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
bool DeleteNode(LNode* p)//删除指定节点
{
	if (p == NULL)//在另一个函数中调用时可能会出现p==NULL的情况，因此判断很有必要
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
LNode* LocateElem(LinkList L, ElemType e)//按值查找
{
	LNode* p = L->next ;//从第一个值开始查找
	while (p != NULL && p->data != e)
		p = p->next;
	return p;//找到返回该指针，找不到返回p
}
bool ListDelete(LinkList* L, int i, ElemType* e)//删除指定位置的节点
//当时我在疑惑好像传L本身也可以改
//真实情况是传L本身确实可以找到那块空间并修改，但是在走出函数时那份临时拷贝会被释放掉
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
	if (p == NULL)//i值不合法
		return false;
	if (p->next == NULL)//i-1后面已没有其他节点
		return false;
	LNode* q = p->next;
	*e = q->data;
	p->next = q->next;
	free(q);
	return true;
}
bool ListInsert(LinkList*L,int i,ElemType e)//在指定位置插入（带头节点）
//不可以传L本身，如果传L本身就是一份临时拷贝，无法在函数内部修改他
//而传L的地址，对其修改就可以改变原先链表的值
//LinkList代表的是这个链表，插入操作会对链表发生改变，因此要传入链表的地址
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
	return InsertNextNode(p, e);
}

int main()
{
	//用头指针创建一个链表，L是指向头节点的
	LinkList L;//LinkList代表的是这个链表
	initlist(&L);
	int i = 1, e = 4;
	ListInsert(&L, i, e);
	return 0;
}