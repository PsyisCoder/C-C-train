#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
using namespace std;
int main()
{
#if 0
//����list�����Ļ���ʹ��
	list<int> lst;
	lst.push_back(10);//β�巨
	lst.push_front(20);//ͷ�巨
	//���������
	list<int>::iterator it;//"::"�������������
	for (it = lst.begin(); it != lst.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	cout << "front:" << lst.front() << endl;
#endif

	//list�����ķ��������
	list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	list<int>::reverse_iterator it1;
	for (it1 = lst.rbegin(); it1 != lst.rend(); it1++)
	{
		cout << *it1 << " ";
	}
	cout << endl;
	return 0;
}