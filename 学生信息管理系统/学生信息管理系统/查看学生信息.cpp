#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "sourse.h"
void Check_Infor(STU_INFOR* phead, int stuNum)
{
	STU_INFOR* ptemp;
	ptemp = phead->next;
	while (ptemp->next != NULL && ptemp->stuNum != stuNum)          //查找学生信息所在链表中的位置；
		ptemp = ptemp->next;
	if (ptemp->stuNum == stuNum)                                 //判断学生信息所在链表中的位置；
	{
		printf("\t学号\t姓名\t成绩1\t成绩2\t成绩3\n");
		printf("\t%d\t%s\t%.1f\t%.1f\t%.1f\n", ptemp->stuNum, ptemp->stuName, ptemp->stuScore1, ptemp->stuScore2, ptemp->stuScore3);
	}
	else
		printf("对不起，没有你要查找的信息！\n");
}