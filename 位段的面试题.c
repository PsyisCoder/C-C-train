#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stddef.h>
int main()
{
	unsigned char puc[4];
	struct tagPIM
	{

		unsigned char ucPim1;		//ռһ���ֽ�
		unsigned char ucData0 : 1;	//ռһ������λ
		unsigned char ucData1 : 2;	//ռ��������λ
		unsigned char ucData2 : 3;	//ռ��������λ
	}*pstPimData;
	pstPimData = (struct tagPIM*)puc;//�������׵�ַǿתΪλ�ε��׵�ַ
	memset(puc, 0, 4);			//���ĸ��ֽڵ����ݶ�����Ϊ0
	pstPimData->ucPim1 = 2;		//��  00000010  �Ž���һ���ֽ�
	pstPimData->ucData0 = 3;	//��  00000011  ��һλ��1���Ž��ڶ����ֽڵ�һ������λ
	pstPimData->ucData1 = 4;	//��  00000100  ����λ��00���Ž��ڶ����ֽڵ���������λ
	pstPimData->ucData2 = 5;	//��  00000101  ����λ��101���Ž��ڶ����ֽڵ���������λ
	//���źþ��ǣ�00000010   00101001   00000000   00000000  Ҳ����0x02 29 00 00
	printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
	return 0;
}