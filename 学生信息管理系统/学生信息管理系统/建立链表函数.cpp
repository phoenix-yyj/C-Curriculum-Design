#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "sourse.h"
STU_INFOR* Setup_Infor(void)
{
	STU_INFOR* phead, * pnew, * ptail;
	phead = (STU_INFOR*)malloc(sizeof(STU_INFOR));      //����һ����̬�洢�ռ䣻
	if (NULL == phead)                                   //�ж��з�����ɹ���
	{
		printf("����һ����̬�洢�ռ�ʧ��\n");
		exit(-1);
	}
	pnew = ptail = phead;
	phead->next = NULL;
	return phead;
}




