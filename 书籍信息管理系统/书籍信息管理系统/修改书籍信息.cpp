#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "sourse.h"
BOOK_INFOR* Mod_Infor(BOOK_INFOR* phead, BOOK_INFOR* modify)             // ����� Head ��ַ����Ҫ�޸ĵĽṹ��ĵ�ַ��
{
	BOOK_INFOR* ptemp;
	ptemp = phead->next;
	while (ptemp->next != NULL && ptemp->bookNum != modify->bookNum)     // ����Ҫ�޸ĵ��鼮��Ϣ���������е�λ��
		ptemp = ptemp->next;
	if (ptemp->bookNum == modify->bookNum)                             //�ж��Ƿ�����Ҫ�޸ĵ�λ��
	{
		strcpy(ptemp->bookName, modify->bookName);
		ptemp->bookPrice= modify->bookPrice;
		strcpy(ptemp->bookPublisher, modify->bookPublisher);
		printf("�޸ĳɹ�\n");
	}
	else                                                            // ���������һֱ�鵽�����β��û�е������
	{
		printf("û�����޸ĵ��鼮����Ϣ�����ݣ�\n");
		printf("�޸�ʧ�ܣ�\n");
	}
	return phead;
}