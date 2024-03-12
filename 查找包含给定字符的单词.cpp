#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
using namespace std;
int main()
{
#if 0
//关于list容器的基本使用
	list<int> lst;
	lst.push_back(10);//尾插法
	lst.push_front(20);//头插法
	//构造迭代器
	list<int>::iterator it;//"::"是作用域操作符
	for (it = lst.begin(); it != lst.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	cout << "front:" << lst.front() << endl;
#endif

	//list容器的反向迭代器
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