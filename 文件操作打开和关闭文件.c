#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main()
{
	//���ļ�test.txt
	//���·��
	//..��ʾ��һ��·��
	//.��ʾ��ǰ·��
	//fopen("..\..\test.txt","r");
	//fopen("test.txt","r");

	//����·����д��,˫б������ΪΪ�˷�ֹת���ַ�
	//fopen("E:\\��̴���\\Project2\\Project2\\test.txt", "r");

	//��һ���ļ�
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)				//�򿪳ɹ�����һ��ָ��FILE���ͣ��ļ���Ϣ������ָ��							
	{							//��ʧ�ܷ���һ����ָ��
		printf("%s", strerror(errno));//��ӡ������Ϣ
		return 0;
	}
	//�򿪳ɹ�
	//���ļ�

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}