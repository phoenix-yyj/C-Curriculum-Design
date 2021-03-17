#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "sourse.h"
void Check_Infor(BOOK_INFOR* phead, int bookNum)
{
	BOOK_INFOR* ptemp;
	ptemp = phead->next;
	while (ptemp->next != NULL && ptemp->bookNum != bookNum)          //查找书籍信息所在链表中的位置；
		ptemp = ptemp->next;
	if (ptemp->bookNum == bookNum)                                 //判断书籍信息所在链表中的位置；
	{
		printf("\t编号\t书名\t价格\t出版商\n");
		printf("\t%d\t%s\t%.2f\t%s\n", ptemp->bookNum, ptemp->bookName, ptemp->bookPrice, ptemp->bookPublisher);
	}
	else
		printf("无效的查找信息！\n");
}