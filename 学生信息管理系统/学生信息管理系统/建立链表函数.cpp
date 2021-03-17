#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "sourse.h"
STU_INFOR* Setup_Infor(void)
{
	STU_INFOR* phead, * pnew, * ptail;
	phead = (STU_INFOR*)malloc(sizeof(STU_INFOR));      //ÉêÇëÒ»¸ö¶¯Ì¬´æ´¢¿Õ¼ä£»
	if (NULL == phead)                                   //ÅÐ¶ÏÓÐ·ñÉêÇë³É¹¦£»
	{
		printf("ÉêÇëÒ»¸ö¶¯Ì¬´æ´¢¿Õ¼äÊ§°Ü\n");
		exit(-1);
	}
	pnew = ptail = phead;
	phead->next = NULL;
	return phead;
}




