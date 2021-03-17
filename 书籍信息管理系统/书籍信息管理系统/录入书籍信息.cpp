#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "sourse.h"
BOOK_INFOR* Input_Infor(BOOK_INFOR* phead, BOOK_INFOR* newstruct)
{
	BOOK_INFOR* pnew, * ptemp;
	pnew = (BOOK_INFOR*)malloc(sizeof(BOOK_INFOR));      //申请一个动态存储空间；
	if (NULL == pnew)                                 //判断是否申请成功；
	{
		printf("申请一个动态存储空间失败\n");
		exit(-1);
	}
	if (NULL == phead->next)                          //判断是否为空链表，如果是，则直接放在链表开头
	{
		*pnew = *newstruct;
		phead->next = pnew;
		pnew->next = NULL;
	}
	else
	{
		ptemp = phead;

		while (ptemp->next->next != NULL && newstruct->bookNum >= ptemp->next->bookNum)      //判断书籍信息录入的位置
			ptemp = ptemp->next;
		if (newstruct->bookNum < ptemp->next->bookNum)                                     //如果是在链表中找到了满足条件的位置，插入链表；
		{
			*pnew = *newstruct;
			pnew->next = ptemp->next;
			ptemp->next = pnew;
		}
		else                                                                              // 这种情况下，直接放在链表为尾；
		{
			*pnew = *newstruct;
			pnew->next = NULL;
			ptemp->next->next = pnew;
		}
	}
	return phead;
}