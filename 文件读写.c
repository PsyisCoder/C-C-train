#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//int main()
//{
//	//���ļ�test.txt
//	//���·��
//	//..��ʾ��һ��·��
//	//.��ʾ��ǰ·��
//	//fopen("..\..\test.txt","r");
//	//fopen("test.txt","r");
//
//	//����·����д��,˫б������ΪΪ�˷�ֹת���ַ�
//	//fopen("E:\\��̴���\\Project2\\Project2\\test.txt", "r");
//
//	//��һ���ļ�
//	//FILE* pf = fopen("test.txt", "r");
//	//if (pf == NULL)				//�򿪳ɹ�����һ��ָ��FILE���ͣ��ļ���Ϣ������ָ��							
//	//{							//��ʧ�ܷ���һ����ָ��
//	//	printf("%s", strerror(errno));//��ӡ������Ϣ
//	//	return 0;
//	//}
//	////�򿪳ɹ�
//	////���ļ�
//
//	////�ر��ļ�
//	//fclose(pf);
//	//pf = NULL;
//
//
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	//д�ļ�
//	fputc('b', pf);
//	fputc('i', pf);
//	fputc('t', pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pfRead = fopen("test.txt", "r");
//	if (pfRead == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	//���ļ�
//	printf("%c",fgetc(pfRead));
//	printf("%c", fgetc(pfRead));
//	printf("%c", fgetc(pfRead));
//	fclose(pfRead);
//	pfRead = NULL;
//	return 0;
//}



int main()
{
	char arr[1024] = "HelloWorld";
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
		return 0;
	}
	//д�ļ�
	fscanf(pf, "%s", arr);
	
	fclose(pf);
	pf == NULL;
	return 0;
}