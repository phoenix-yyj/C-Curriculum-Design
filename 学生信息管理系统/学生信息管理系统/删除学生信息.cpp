#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "sourse.h"
STU_INFOR* Dle_Infor(STU_INFOR* phead, int stuNum)
{
	STU_INFOR* ptemp, * pdel;
	ptemp = phead;
	while (ptemp->next->next != NULL && ptemp->next->stuNum != stuNum)     //����Ҫɾ����ѧ����Ϣ���������е�λ��
		ptemp = ptemp->next;
	if (ptemp->next->stuNum == stuNum)                                     //�ж��Ƿ���Ҫɾ����λ��
	{
		pdel = ptemp->next;
		ptemp->next = pdel->next;
		free(pdel);
		printf("��ϲ�㣬ɾ���ɹ�\n");
	}
	else
	{
		printf("û����Ҫ���ҵ����ݣ�\n");
		printf("������˼��ɾ��ʧ�ܣ�\n");
	}
	return phead;
}

