#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "sourse.h"
STU_INFOR* Mod_Infor(STU_INFOR* phead, STU_INFOR* modify)             // ����� Head ��ַ����Ҫ�޸ĵĽṹ��ĵ�ַ��
{
	STU_INFOR* ptemp;
	ptemp = phead->next;
	while (ptemp->next != NULL && ptemp->stuNum != modify->stuNum)     // ����Ҫ�޸ĵ�ѧ����Ϣ���������е�λ��
		ptemp = ptemp->next;
	if (ptemp->stuNum == modify->stuNum)                             //�ж��Ƿ�����Ҫ�޸ĵ�λ��
	{
		strcpy(ptemp->stuName, modify->stuName);
		ptemp->stuScore1 = modify->stuScore1;
		ptemp->stuScore2 = modify->stuScore2;
		ptemp->stuScore3 = modify->stuScore3;
		printf("��ϲ�㣬�޸ĳɹ�\n");
	}
	else                                                            // ���������һֱ�鵽�����β��û�е������
	{
		printf("û�����޸ĵ�ѧ������Ϣ�����ݣ�\n");
		printf("������˼���޸�ʧ�ܣ�\n");
	}
	return phead;
}