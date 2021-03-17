#include <stdio.h>
#include<stdlib.h>
#include "sourse.h"
void Display_Infor(BOOK_INFOR* phead)
{
	system("cls");
	BOOK_INFOR* ptemp;
	if (phead->next == NULL)               // 空链表；
		printf("对不起，没有内容\n");
	else
	{
		ptemp = phead->next;
		printf("\t编号\t书名\t价格\t出版商\n");
		while (ptemp->next != NULL)
		{
			printf("\t%d\t%s\t%.2f\t%s\n", ptemp->bookNum, ptemp->bookName, ptemp->bookPrice, ptemp->bookPublisher);
			ptemp = ptemp->next;
		}
		printf("\t%d\t%s\t%.2f\t%s\n", ptemp->bookNum, ptemp->bookName, ptemp->bookPrice, ptemp->bookPublisher);
	}
}