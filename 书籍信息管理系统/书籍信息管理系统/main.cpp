#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "sourse.h"


/*###############################################################
######################   ������   ##############################*/


int main()
{
	FILE* fp;
	char state;                                    //���ڴ洢һ���ַ���y or Y) ��
	BOOK_INFOR newstruct = { 0,"0",0.000,"0" }, * head, * Ftemp, * Ftemp2;  // Ftemp��Ftepm2�ڶ�д����ʱʹ�á�
	int select = 0, num = 0;                            // ����һ��ѡ��״̬��select��һ���鼮��ѧ��num��
	head = (BOOK_INFOR*)malloc(sizeof(BOOK_INFOR));      // ������һ����̬�ռ��head������Ұָ�룻
	printf("\n\n\n\n\n\t\t\t\t\t��ӭ�����鼮����ϵͳ\n\n\n\n\t\t\t\t\t\t\t\tby ���Ƚ�\n");
	printf("\n\n\n����֮ǰ�Ƿ�򿪲������������Ϣ������ǣ��� 'Y' �����룬���� 'N' ����������ĸ�½����ݣ�\n");
	state = getchar();
	getchar();                                     // �������λس�����


  /*###############################################################
  ######################    ��������ģ��   #######################*/


	if (state == 'y' || state == 'Y')
	{
		fp = fopen("data.dat", "rb");
		/*###############################################################*/
		if (NULL == fp)                                // �ж��ļ��Ƿ�򿪳ɹ�
		{
			printf("�ļ������ڣ����ļ�ʧ��\n");
			printf("�������˳��������������");
			getchar();
			exit(-1);
		}
		/*###############################################################*/
		Ftemp = head;
		while (1 == fread(Ftemp, sizeof(BOOK_INFOR), 1, fp))      // �ж��ļ��Ƿ��ȡ���
		{
			Ftemp2 = Ftemp;
			Ftemp->next = (BOOK_INFOR*)malloc(sizeof(BOOK_INFOR));
			Ftemp = Ftemp->next;
		}
		Ftemp->next = NULL;                // �ѵ������������һ��λ�õ�next���ΪNULL;
		free(Ftemp);                        // �ͷŵ�ûʹ�õĿռ䣻
		fclose(fp);
		printf("������Ϣ�ɹ����밴G�ɻ�������������\n");
		getchar();
		getchar();                                   // �������εĻس�����
	}
	/*###############################################################*/
	else
	{
		free(head);                               // �ͷŵ��ļ���ʼ��������Ŀռ䣻
		head = Setup_Infor();                     // ������������
	}
	/*################################################################
	  ###################    ��������ѭ��     ########################
	  ###############################################################*/
LOOP:do
{
	ScreenDisplay();                             // ��ʾ������棻
	printf("\n\n\n\n�������Ӧ����\n");
	scanf("%d", &select);
	getchar();                                   // �������εĻس�����
	switch (select) {
	case 1:                                  // ¼���鼮��Ϣ��ڣ�
		/*###############################################################
		####################   ¼���鼮��Ϣģ��    #####################*/
		do
		{
			ScreenDisplay();
			printf("���������鼮�ı�ţ�\n");
			scanf("%d", &newstruct.bookNum);
			getchar();                            // �������λس�����
			printf("���������鼮��������\n");
			scanf("%s", newstruct.bookName);
			getchar();                            // �������εĻس����� 
			printf("���������鼮�ļ۸� \n");
			scanf("%f", &newstruct.bookPrice);
			getchar();                           // �������εĻس�����
			printf("���������鼮�ĳ����̣� \n");
			scanf("%s", newstruct.bookPublisher);
			getchar();
			Input_Infor(head, &newstruct);
			printf("�Ƿ��������,Y or N ?      \n");
			state = getchar();
			getchar();                            // �������εĻس�����
		} while (state == 'y' || state == 'Y');
		break;
	case 2:                                       // �鿴�鼮��Ϣ��ڣ�
		/*###############################################################
		####################   �鿴�鼮��Ϣģ��    ####################*/
		do
		{
			ScreenDisplay();
			printf("����������Ҫ�鿴���鼮�ı�� \n");
			scanf("%d", &num);
			getchar();                      // �������εĻس�����
			Check_Infor(head, num);
			printf("�Ƿ�����鿴�鼮��Ϣ, Y or N ?      \n");
			state = getchar();
			getchar();                      // �������εĻس�����
		} while (state == 'y' || state == 'Y');
		break;
	case 3:                                 // ɾ���鼮��Ϣ��ڣ�
		/*###############################################################
		####################   ɾ���鼮��Ϣģ��    ####################*/
		do
		{
			ScreenDisplay();
			printf("��������Ҫɾ�����鼮�ı�ţ�\n");
			scanf("%d", &num);
			getchar();                                   // �������εĻس�����
			printf("ȷ��Ҫɾ����  ��Y or N��");
			state = getchar();
			getchar();                                   // �������εĻس�����
			if (state == 'Y' || state == 'y')
				head = Dle_Infor(head, num);
			printf("�Ƿ����ɾ���鼮��Ϣ, Y or N ?      \n");
			state = getchar();
			getchar();                                   // �������εĻس�����
		} while (state == 'y' || state == 'Y');
		break;
	case 4:                                 // �޸��鼮��Ϣ��ڣ�
		/*###############################################################
		####################   �޸��鼮��Ϣģ��    ####################*/

		do
		{
			ScreenDisplay();
			printf("����������Ҫ�޸ĵ��鼮�ı�ţ�\n");
			scanf("%d", &newstruct.bookNum);
			getchar();                                   // �������εĻس�����
			printf("����������Ҫ�޸ĵ��鼮��������\n");
			scanf("%s", newstruct.bookName);
			getchar();                                   // �������εĻس�����
			printf("����������Ҫ�޸ĵ��鼮�ļ۸� \n");
			scanf("%f", &newstruct.bookPrice);
			getchar();                                   // �������εĻس�����
			printf("����������Ҫ�޸ĵ��鼮�ĳ����̣� \n");
			scanf("%s", newstruct.bookPublisher);
			getchar();                                   // �������εĻس�����
			head = Mod_Infor(head, &newstruct);
			printf("�Ƿ�����޸��鼮��Ϣ, Y or N ?      \n");
			state = getchar();
			getchar();                                   // �������εĻس�����
		} while (state == 'y' || state == 'Y');
		break;
	case 5:
		/*###############################################################
		####################   ��ʾ�����鼮��Ϣģ��    ####################*/
		BubbleSort(head);                                //����
		do
		{
			Display_Infor(head);
			printf("�Ƿ���Ҫ���ظ���ʾһ���鼮��Ϣ, Y or N ?      \n");
			state = getchar();
			getchar();                                   // �������εĻس�����
		} while (state == 'y' || state == 'Y');
		break;
	case 6:                                // �˳��鼮����ϵͳ��ڣ�
		/*###############################################################
		####################   �˳��鼮����ϵͳģ��    ####################*/


		printf("�Ƿ񱣴����ϲ����� Y or N ? ");
		state = getchar();
		getchar();                                   // �������εĻس�����
		if (state == 'y' || state == 'Y')                // ��һ��������棻
		{
			fp = fopen("data.dat", "wb");
			/*###############################################################*/
			if (NULL == fp)                              // �ж��ļ��Ƿ��ʧ�ܣ�
			{
				printf("Open files error\n");
				exit(-1);
			}
			/*###############################################################*/
			Ftemp = head;
			while (Ftemp->next != NULL)                   // д�ļ����ж�������
			{
				fwrite((void*)Ftemp, sizeof(BOOK_INFOR), 1, fp);
				Ftemp = Ftemp->next;
			}
			fwrite((void*)Ftemp, sizeof(BOOK_INFOR), 1, fp);  // ��ָ������һ��д����ļ��У�            
			fclose(fp);
			printf("��ϲ�㣬����ɹ���\n");
		}
		printf("�������������\n");
		getchar();
		exit(0);
		break;
		/*###############################################################
		############    ������Ĳ�����Ч������ģ��   ###################*/
	default:printf("����������󣬰����������������\n ");
		getchar();
	}
} while (1);
/*################################################################
###################     ����,����ѭ������    #####################
###############################################################*/
return 0;
}