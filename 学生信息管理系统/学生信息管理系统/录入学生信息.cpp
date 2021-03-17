#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "sourse.h"
STU_INFOR* Input_Infor(STU_INFOR* phead, STU_INFOR* newstruct)
{
	STU_INFOR* pnew, * ptemp;
	pnew = (STU_INFOR*)malloc(sizeof(STU_INFOR));      //����һ����̬�洢�ռ䣻
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

		while (ptemp->next->next != NULL && newstruct->stuNum >= ptemp->next->stuNum)      //�ж�ѧ����Ϣ¼���λ��
			ptemp = ptemp->next;
		if (newstruct->stuNum < ptemp->next->stuNum)                                     //��������������ҵ�������������λ�ã���������
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
