#include <stdio.h>
#include<stdlib.h>
#include "sourse.h"
void Display_Infor(BOOK_INFOR* phead)
{
	system("cls");
	BOOK_INFOR* ptemp;
	if (phead->next == NULL)               // ������
		printf("�Բ���û������\n");
	else
	{
		ptemp = phead->next;
		printf("\t���\t����\t�۸�\t������\n");
		while (ptemp->next != NULL)
		{
			printf("\t%d\t%s\t%.2f\t%s\n", ptemp->bookNum, ptemp->bookName, ptemp->bookPrice, ptemp->bookPublisher);
			ptemp = ptemp->next;
		}
		printf("\t%d\t%s\t%.2f\t%s\n", ptemp->bookNum, ptemp->bookName, ptemp->bookPrice, ptemp->bookPublisher);
	}
}