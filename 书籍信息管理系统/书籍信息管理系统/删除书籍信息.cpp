#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "sourse.h"
BOOK_INFOR* Dle_Infor(BOOK_INFOR* phead, int bookNum)
{
	BOOK_INFOR* ptemp, * pdel;
	ptemp = phead;
	while (ptemp->next->next != NULL && ptemp->next->bookNum != bookNum)     //����Ҫɾ�����鼮��Ϣ���������е�λ��
		ptemp = ptemp->next;
	if (ptemp->next->bookNum == bookNum)                                     //�ж��Ƿ���Ҫɾ����λ��
	{
		pdel = ptemp->next;
		ptemp->next = pdel->next;
		free(pdel);
		printf("ɾ���ɹ�\n");
	}
	else
	{
		printf("��Ч�Ĳ������ݣ�\n");
		printf("ɾ��ʧ�ܣ�\n");
	}
	return phead;
}