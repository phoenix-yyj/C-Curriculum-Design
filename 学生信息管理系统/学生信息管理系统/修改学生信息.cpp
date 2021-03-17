#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "sourse.h"
STU_INFOR* Mod_Infor(STU_INFOR* phead, STU_INFOR* modify)             // 链表的 Head 地址与需要修改的结构体的地址；
{
	STU_INFOR* ptemp;
	ptemp = phead->next;
	while (ptemp->next != NULL && ptemp->stuNum != modify->stuNum)     // 查找要修改的学生信息所在链表中的位置
		ptemp = ptemp->next;
	if (ptemp->stuNum == modify->stuNum)                             //判断是否是是要修改的位置
	{
		strcpy(ptemp->stuName, modify->stuName);
		ptemp->stuScore1 = modify->stuScore1;
		ptemp->stuScore2 = modify->stuScore2;
		ptemp->stuScore3 = modify->stuScore3;
		printf("恭喜你，修改成功\n");
	}
	else                                                            // 这种情况是一直查到链表结尾仍没有的情况；
	{
		printf("没有你修改的学生的信息的内容！\n");
		printf("不好意思，修改失败！\n");
	}
	return phead;
}