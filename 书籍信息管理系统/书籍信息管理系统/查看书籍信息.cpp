#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "sourse.h"
void Check_Infor(BOOK_INFOR* phead, int bookNum)
{
	BOOK_INFOR* ptemp;
	ptemp = phead->next;
	while (ptemp->next != NULL && ptemp->bookNum != bookNum)          //�����鼮��Ϣ���������е�λ�ã�
		ptemp = ptemp->next;
	if (ptemp->bookNum == bookNum)                                 //�ж��鼮��Ϣ���������е�λ�ã�
	{
		printf("\t���\t����\t�۸�\t������\n");
		printf("\t%d\t%s\t%.2f\t%s\n", ptemp->bookNum, ptemp->bookName, ptemp->bookPrice, ptemp->bookPublisher);
	}
	else
		printf("��Ч�Ĳ�����Ϣ��\n");
}