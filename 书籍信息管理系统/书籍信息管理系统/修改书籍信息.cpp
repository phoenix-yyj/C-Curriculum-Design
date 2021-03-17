#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "sourse.h"
BOOK_INFOR* Mod_Infor(BOOK_INFOR* phead, BOOK_INFOR* modify)             // 链表的 Head 地址与需要修改的结构体的地址；
{
	BOOK_INFOR* ptemp;
	ptemp = phead->next;
	while (ptemp->next != NULL && ptemp->bookNum != modify->bookNum)     // 查找要修改的书籍信息所在链表中的位置
		ptemp = ptemp->next;
	if (ptemp->bookNum == modify->bookNum)                             //判断是否是是要修改的位置
	{
		strcpy(ptemp->bookName, modify->bookName);
		ptemp->bookPrice= modify->bookPrice;
		strcpy(ptemp->bookPublisher, modify->bookPublisher);
		printf("修改成功\n");
	}
	else                                                            // 这种情况是一直查到链表结尾仍没有的情况；
	{
		printf("没有你修改的书籍的信息的内容！\n");
		printf("修改失败！\n");
	}
	return phead;
}