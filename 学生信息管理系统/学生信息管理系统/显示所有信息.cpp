#include <stdio.h>
#include<stdlib.h>
#include "sourse.h"
void Display_Infor(STU_INFOR* phead)
{
	system("cls");
	STU_INFOR* ptemp;
	if (phead->next == NULL)               // ������
		printf("�Բ���û������\n");
	else
	{
		ptemp = phead->next;
		printf("\tѧ��\t����\t�ɼ�1\t�ɼ�2\t�ɼ�3\n");
		while (ptemp->next != NULL)
		{
			printf("\t%d\t%s\t%.1f\t%.1f\t%.1f\n", ptemp->stuNum, ptemp->stuName, ptemp->stuScore1, ptemp->stuScore2, ptemp->stuScore3);
			ptemp = ptemp->next;
		}
		printf("\t%d\t%s\t%.1f\t%.1f\t%.1f\n", ptemp->stuNum, ptemp->stuName, ptemp->stuScore1, ptemp->stuScore2, ptemp->stuScore3);
	}
}
