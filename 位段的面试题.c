#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stddef.h>
int main()
{
	unsigned char puc[4];
	struct tagPIM
	{

		unsigned char ucPim1;		//占一个字节
		unsigned char ucData0 : 1;	//占一个比特位
		unsigned char ucData1 : 2;	//占两个比特位
		unsigned char ucData2 : 3;	//占三个比特位
	}*pstPimData;
	pstPimData = (struct tagPIM*)puc;//把数组首地址强转为位段的首地址
	memset(puc, 0, 4);			//把四个字节的内容都设置为0
	pstPimData->ucPim1 = 2;		//把  00000010  放进第一个字节
	pstPimData->ucData0 = 3;	//把  00000011  的一位（1）放进第二个字节的一个比特位
	pstPimData->ucData1 = 4;	//把  00000100  的两位（00）放进第二个字节的两个比特位
	pstPimData->ucData2 = 5;	//把  00000101  的三位（101）放进第二个字节的三个比特位
	//最后放好就是：00000010   00101001   00000000   00000000  也就是0x02 29 00 00
	printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
	return 0;
}