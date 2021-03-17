#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "sourse.h"
BOOK_INFOR* Setup_Infor(void)
{
	BOOK_INFOR* phead, * pnew, * ptail;
	phead = (BOOK_INFOR*)malloc(sizeof(BOOK_INFOR));      //ÉêÇëÒ»¸ö¶¯Ì¬´æ´¢¿Õ¼ä£»
	if (NULL == phead)                                   //ÅÐ¶ÏÊÇ·ñÉêÇë³É¹¦£»
	{
		printf("ÉêÇëÒ»¸ö¶¯Ì¬´æ´¢¿Õ¼äÊ§°Ü\n");
		exit(-1);
	}
	pnew = ptail = phead;
	phead->next = NULL;
	return phead;
}