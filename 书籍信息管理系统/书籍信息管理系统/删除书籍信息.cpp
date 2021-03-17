#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "sourse.h"
BOOK_INFOR* Dle_Infor(BOOK_INFOR* phead, int bookNum)
{
	BOOK_INFOR* ptemp, * pdel;
	ptemp = phead;
	while (ptemp->next->next != NULL && ptemp->next->bookNum != bookNum)     //查找要删除的书籍信息所在链表中的位置
		ptemp = ptemp->next;
	if (ptemp->next->bookNum == bookNum)                                     //判断是否是要删除的位置
	{
		pdel = ptemp->next;
		ptemp->next = pdel->next;
		free(pdel);
		printf("删除成功\n");
	}
	else
	{
		printf("无效的查找内容！\n");
		printf("删除失败！\n");
	}
	return phead;
}