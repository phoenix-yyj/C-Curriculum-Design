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
	STU_INFOR newstruct = { 0,"0",0.0,0.0,0.0 }, * head, * Ftemp, * Ftemp2;  // Ftemp��Ftepm2�ڶ�д����ʱʹ�á�
	int select = 0, num = 0;                            // ����һ��ѡ��״̬��select��һ��ѧ����ѧ��num��
	head = (STU_INFOR*)malloc(sizeof(STU_INFOR));      // ������һ����̬�ռ��head������Ұָ�룻
	printf("\n\n\n\n\n\t\t\t\t\t��ӭ����ѧ������ϵͳ\n\n\n\n\t\t\t\t\t\t\t\tby ���Ƚ�\n");
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
		while (1 == fread(Ftemp, sizeof(STU_INFOR), 1, fp))      // �ж��ļ��Ƿ��ȡ���
		{
			Ftemp2 = Ftemp;
			Ftemp->next = (STU_INFOR*)malloc(sizeof(STU_INFOR));
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
		case 1:                                  // ¼��ѧ����Ϣ��ڣ�
			/*###############################################################
			####################   ¼��ѧ����Ϣģ��    #####################*/
			do
			{
				ScreenDisplay();
				printf("��������ѧ����ѧ�ţ�\n");
				scanf("%d", &newstruct.stuNum);
				getchar();                            // �������λس�����
				printf("��������ѧ����������\n");
				scanf("%s", newstruct.stuName);
				getchar();                            // �������εĻس����� 
				printf("��������ѧ���ĵ�һ�ſ�Ŀ�ɼ��� \n");
				scanf("%f", &newstruct.stuScore1);
				getchar();                           // �������εĻس�����
				printf("��������ѧ���ĵڶ��ſ�Ŀ�ɼ��� \n");
				scanf("%f", &newstruct.stuScore2);
				getchar();
				printf("��������ѧ���ĵ����ſ�Ŀ�ɼ��� \n");
				scanf("%f", &newstruct.stuScore3);
				getchar();
				Input_Infor(head, &newstruct);
				printf("�Ƿ��������,Y or N ?      \n");
				state = getchar();
				getchar();                            // �������εĻس�����
			} while (state == 'y' || state == 'Y');
			break;
		case 2:                                       // �鿴ѧ����Ϣ��ڣ�
			/*###############################################################
			####################   �鿴ѧ����Ϣģ��    ####################*/
			do
			{
				ScreenDisplay();
				printf("����������Ҫ�鿴��ѧ����ѧ�� \n");
				scanf("%d", &num);
				getchar();                      // �������εĻس�����
				Check_Infor(head, num);
				printf("�Ƿ�����鿴ѧ����Ϣ, Y or N ?      \n");
				state = getchar();
				getchar();                      // �������εĻس�����
			} while (state == 'y' || state == 'Y');
			break;
		case 3:                                 // ɾ��ѧ����Ϣ��ڣ�
			/*###############################################################
			####################   ɾ��ѧ����Ϣģ��    ####################*/
			do
			{
				ScreenDisplay();
				printf("��������Ҫɾ����ѧ����ѧ�ţ�\n");
				scanf("%d", &num);
				getchar();                                   // �������εĻس�����
				printf("ȷ��Ҫɾ����  ��Y or N��");
				state = getchar();
				getchar();                                   // �������εĻس�����
				if (state == 'Y' || state == 'y')
					head = Dle_Infor(head, num);
				printf("�Ƿ����ɾ��ѧ����Ϣ, Y or N ?      \n");
				state = getchar();
				getchar();                                   // �������εĻس�����
			} while (state == 'y' || state == 'Y');
			break;
		case 4:                                 // �޸�ѧ����Ϣ��ڣ�
			/*###############################################################
			####################   �޸�ѧ����Ϣģ��    ####################*/

			do
			{
				ScreenDisplay();
				printf("����������Ҫ�޸ĵ�ѧ����ѧ�ţ�\n");
				scanf("%d", &newstruct.stuNum);
				getchar();                                   // �������εĻس�����
				printf("����������Ҫ�޸ĵ�ѧ����������\n");
				scanf("%s", newstruct.stuName);
				getchar();                                   // �������εĻس�����
				printf("����������Ҫ�޸ĵ�ѧ���ĵ�һ�ſ�Ŀ�ɼ��� \n");
				scanf("%f", &newstruct.stuScore1);
				getchar();                                   // �������εĻس�����
				printf("����������Ҫ�޸ĵ�ѧ���ĵڶ��ſ�Ŀ�ɼ��� \n");
				scanf("%f", &newstruct.stuScore2);
				getchar();                                   // �������εĻس�����
				printf("����������Ҫ�޸ĵ�ѧ���ĵ����ſ�Ŀ�ɼ��� \n");
				scanf("%f", &newstruct.stuScore3);
				getchar();                                   // �������εĻس�����
				head = Mod_Infor(head, &newstruct);
				printf("�Ƿ�����޸�ѧ����Ϣ, Y or N ?      \n");
				state = getchar();
				getchar();                                   // �������εĻس�����
			} while (state == 'y' || state == 'Y');
			break;
		case 5:
			/*###############################################################
			####################   ð������ģ��            ####################*/
			do
			{
				system("cls");
				printf("\n\n\n\n\n");
				printf("\t\t\t### 1  �� �ɼ�1 ��������\n");
				printf("\t\t\t### 2  �� �ɼ�2 ��������\n");
				printf("\t\t\t### 3  �� �ɼ�3 ��������\n");
				scanf("%d", &select);
				getchar();                                   // �������εĻس�����
				switch (select)
				{
				case 1:
					BubbleSort1(head);
					break;
				case 2:
					BubbleSort2(head);
					break;
				case 3:
					BubbleSort3(head);
					break;
				default:
					printf("����������󣬰����������������\n ");
					getchar();
					goto LOOP;
					break;
				}
				Display_Infor(head);
				printf("�Ƿ񷵻�������, Y or N ?      \n");
				state = getchar();
				getchar();                                   // �������εĻس�����
			} while (state == 'n' || state == 'N');
			break;
		case 6:
			/*###############################################################
			####################   ��ʾ����ѧ����Ϣģ��    ####################*/
			do
			{
				Display_Infor(head);
				printf("�Ƿ���Ҫ���ظ���ʾһ��ѧ����Ϣ, Y or N ?      \n");
				state = getchar();
				getchar();                                   // �������εĻس�����
			} while (state == 'y' || state == 'Y');
			break;
		case 7:                                // �˳�ѧ������ϵͳ��ڣ�
			/*###############################################################
			####################   �˳�ѧ������ϵͳģ��    ####################*/


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
					fwrite((void*)Ftemp, sizeof(STU_INFOR), 1, fp);
					Ftemp = Ftemp->next;
				}
				fwrite((void*)Ftemp, sizeof(STU_INFOR), 1, fp);  // ��ָ������һ��д����ļ��У�            
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