#include <stdio.h>
#include<stdlib.h>
#include "sourse.h"
void Display_Infor(STU_INFOR* phead)
{
	system("cls");
	STU_INFOR* ptemp;
	if (phead->next == NULL)               // 空链表；
		printf("对不起，没有内容\n");
	else
	{
		ptemp = phead->next;
		printf("\t学号\t姓名\t成绩1\t成绩2\t成绩3\n");
		while (ptemp->next != NULL)
		{
			printf("\t%d\t%s\t%.1f\t%.1f\t%.1f\n", ptemp->stuNum, ptemp->stuName, ptemp->stuScore1, ptemp->stuScore2, ptemp->stuScore3);
			ptemp = ptemp->next;
		}
		printf("\t%d\t%s\t%.1f\t%.1f\t%.1f\n", ptemp->stuNum, ptemp->stuName, ptemp->stuScore1, ptemp->stuScore2, ptemp->stuScore3);
	}
}
