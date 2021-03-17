#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "sourse.h"
BOOK_INFOR* Input_Infor(BOOK_INFOR* phead, BOOK_INFOR* newstruct)
{
	BOOK_INFOR* pnew, * ptemp;
	pnew = (BOOK_INFOR*)malloc(sizeof(BOOK_INFOR));      //����һ����̬�洢�ռ䣻
	if (NULL == pnew)                                 //�ж��Ƿ�����ɹ���
	{
		printf("����һ����̬�洢�ռ�ʧ��\n");
		exit(-1);
	}
	if (NULL == phead->next)                          //�ж��Ƿ�Ϊ����������ǣ���ֱ�ӷ�������ͷ
	{
		*pnew = *newstruct;
		phead->next = pnew;
		pnew->next = NULL;
	}
	else
	{
		ptemp = phead;

		while (ptemp->next->next != NULL && newstruct->bookNum >= ptemp->next->bookNum)      //�ж��鼮��Ϣ¼���λ��
			ptemp = ptemp->next;
		if (newstruct->bookNum < ptemp->next->bookNum)                                     //��������������ҵ�������������λ�ã���������
		{
			*pnew = *newstruct;
			pnew->next = ptemp->next;
			ptemp->next = pnew;
		}
		else                                                                              // ��������£�ֱ�ӷ�������Ϊβ��
		{
			*pnew = *newstruct;
			pnew->next = NULL;
			ptemp->next->next = pnew;
		}
	}
	return phead;
}