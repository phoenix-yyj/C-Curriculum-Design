#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "sourse.h"
BOOK_INFOR* Setup_Infor(void)
{
	BOOK_INFOR* phead, * pnew, * ptail;
	phead = (BOOK_INFOR*)malloc(sizeof(BOOK_INFOR));      //����һ����̬�洢�ռ䣻
	if (NULL == phead)                                   //�ж��Ƿ�����ɹ���
	{
		printf("����һ����̬�洢�ռ�ʧ��\n");
		exit(-1);
	}
	pnew = ptail = phead;
	phead->next = NULL;
	return phead;
}