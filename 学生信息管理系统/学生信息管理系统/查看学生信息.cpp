#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "sourse.h"
void Check_Infor(STU_INFOR* phead, int stuNum)
{
	STU_INFOR* ptemp;
	ptemp = phead->next;
	while (ptemp->next != NULL && ptemp->stuNum != stuNum)          //����ѧ����Ϣ���������е�λ�ã�
		ptemp = ptemp->next;
	if (ptemp->stuNum == stuNum)                                 //�ж�ѧ����Ϣ���������е�λ�ã�
	{
		printf("\tѧ��\t����\t�ɼ�1\t�ɼ�2\t�ɼ�3\n");
		printf("\t%d\t%s\t%.1f\t%.1f\t%.1f\n", ptemp->stuNum, ptemp->stuName, ptemp->stuScore1, ptemp->stuScore2, ptemp->stuScore3);
	}
	else
		printf("�Բ���û����Ҫ���ҵ���Ϣ��\n");
}