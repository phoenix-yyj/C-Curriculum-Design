#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "sourse.h"


/*###############################################################
######################   主程序   ##############################*/


int main()
{
	FILE* fp;
	char state;                                    //用于存储一个字符（y or Y) ；
	STU_INFOR newstruct = { 0,"0",0.0,0.0,0.0 }, * head, * Ftemp, * Ftemp2;  // Ftemp与Ftepm2在读写函数时使用。
	int select = 0, num = 0;                            // 定义一个选择状态数select和一个学生的学号num；
	head = (STU_INFOR*)malloc(sizeof(STU_INFOR));      // 先申请一个动态空间给head，避免野指针；
	printf("\n\n\n\n\n\t\t\t\t\t欢迎进入学生管理系统\n\n\n\n\t\t\t\t\t\t\t\tby 严奕杰\n");
	printf("\n\n\n请问之前是否打开并保存过数据信息，如果是，则按 'Y' 键载入，否则按 'N' 键或其它字母新建数据！\n");
	state = getchar();
	getchar();                                     // 消除本次回车键；


  /*###############################################################
  ######################    载入数据模块   #######################*/


	if (state == 'y' || state == 'Y')
	{
		fp = fopen("data.dat", "rb");
		/*###############################################################*/
		if (NULL == fp)                                // 判断文件是否打开成功
		{
			printf("文件不存在，打开文件失败\n");
			printf("本程序将退出，按任意键结束");
			getchar();
			exit(-1);
		}
		/*###############################################################*/
		Ftemp = head;
		while (1 == fread(Ftemp, sizeof(STU_INFOR), 1, fp))      // 判断文件是否读取完毕
		{
			Ftemp2 = Ftemp;
			Ftemp->next = (STU_INFOR*)malloc(sizeof(STU_INFOR));
			Ftemp = Ftemp->next;
		}
		Ftemp->next = NULL;                // 把导入的链表的最后一个位置的next标记为NULL;
		free(Ftemp);                        // 释放掉没使用的空间；
		fclose(fp);
		printf("载入信息成功，请按G徤或其它键继续！\n");
		getchar();
		getchar();                                   // 消除本次的回车键；
	}
	/*###############################################################*/
	else
	{
		free(head);                               // 释放掉文件开始部分申请的空间；
		head = Setup_Infor();                     // 建立函数链表；
	}
	/*################################################################
	  ###################    进入整个循环     ########################
	  ###############################################################*/
	LOOP:do
	{
		ScreenDisplay();                             // 显示输出介面；
		printf("\n\n\n\n请输入对应数字\n");
		scanf("%d", &select);
		getchar();                                   // 消除本次的回车键；
		switch (select) {
		case 1:                                  // 录入学生信息入口；
			/*###############################################################
			####################   录入学生信息模块    #####################*/
			do
			{
				ScreenDisplay();
				printf("请你输入学生的学号：\n");
				scanf("%d", &newstruct.stuNum);
				getchar();                            // 消除本次回车键；
				printf("请你输入学生的姓名：\n");
				scanf("%s", newstruct.stuName);
				getchar();                            // 消除本次的回车键； 
				printf("请你输入学生的第一门科目成绩： \n");
				scanf("%f", &newstruct.stuScore1);
				getchar();                           // 消除本次的回车键；
				printf("请你输入学生的第二门科目成绩： \n");
				scanf("%f", &newstruct.stuScore2);
				getchar();
				printf("请你输入学生的第三门科目成绩： \n");
				scanf("%f", &newstruct.stuScore3);
				getchar();
				Input_Infor(head, &newstruct);
				printf("是否继续输入,Y or N ?      \n");
				state = getchar();
				getchar();                            // 消除本次的回车键；
			} while (state == 'y' || state == 'Y');
			break;
		case 2:                                       // 查看学生信息入口；
			/*###############################################################
			####################   查看学生信息模块    ####################*/
			do
			{
				ScreenDisplay();
				printf("请你输入需要查看的学生的学号 \n");
				scanf("%d", &num);
				getchar();                      // 消除本次的回车键；
				Check_Infor(head, num);
				printf("是否继续查看学生信息, Y or N ?      \n");
				state = getchar();
				getchar();                      // 消除本次的回车键；
			} while (state == 'y' || state == 'Y');
			break;
		case 3:                                 // 删除学生信息入口；
			/*###############################################################
			####################   删除学生信息模块    ####################*/
			do
			{
				ScreenDisplay();
				printf("请输入需要删除的学生的学号：\n");
				scanf("%d", &num);
				getchar();                                   // 消除本次的回车键；
				printf("确定要删除？  （Y or N）");
				state = getchar();
				getchar();                                   // 消除本次的回车键；
				if (state == 'Y' || state == 'y')
					head = Dle_Infor(head, num);
				printf("是否继续删除学生信息, Y or N ?      \n");
				state = getchar();
				getchar();                                   // 消除本次的回车键；
			} while (state == 'y' || state == 'Y');
			break;
		case 4:                                 // 修改学生信息入口；
			/*###############################################################
			####################   修改学生信息模块    ####################*/

			do
			{
				ScreenDisplay();
				printf("请你输入需要修改的学生的学号：\n");
				scanf("%d", &newstruct.stuNum);
				getchar();                                   // 消除本次的回车键；
				printf("请你输入需要修改的学生的姓名：\n");
				scanf("%s", newstruct.stuName);
				getchar();                                   // 消除本次的回车键；
				printf("请你输入需要修改的学生的第一门科目成绩： \n");
				scanf("%f", &newstruct.stuScore1);
				getchar();                                   // 消除本次的回车键；
				printf("请你输入需要修改的学生的第二门科目成绩： \n");
				scanf("%f", &newstruct.stuScore2);
				getchar();                                   // 消除本次的回车键；
				printf("请你输入需要修改的学生的第三门科目成绩： \n");
				scanf("%f", &newstruct.stuScore3);
				getchar();                                   // 消除本次的回车键；
				head = Mod_Infor(head, &newstruct);
				printf("是否继续修改学生信息, Y or N ?      \n");
				state = getchar();
				getchar();                                   // 消除本次的回车键；
			} while (state == 'y' || state == 'Y');
			break;
		case 5:
			/*###############################################################
			####################   冒泡排序模块            ####################*/
			do
			{
				system("cls");
				printf("\n\n\n\n\n");
				printf("\t\t\t### 1  按 成绩1 降序排序\n");
				printf("\t\t\t### 2  按 成绩2 降序排序\n");
				printf("\t\t\t### 3  按 成绩3 降序排序\n");
				scanf("%d", &select);
				getchar();                                   // 消除本次的回车键；
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
					printf("你输入的有误，按任意键返回主界面\n ");
					getchar();
					goto LOOP;
					break;
				}
				Display_Infor(head);
				printf("是否返回主界面, Y or N ?      \n");
				state = getchar();
				getchar();                                   // 消除本次的回车键；
			} while (state == 'n' || state == 'N');
			break;
		case 6:
			/*###############################################################
			####################   显示所有学生信息模块    ####################*/
			do
			{
				Display_Infor(head);
				printf("是否需要再重复显示一次学生信息, Y or N ?      \n");
				state = getchar();
				getchar();                                   // 消除本次的回车键；
			} while (state == 'y' || state == 'Y');
			break;
		case 7:                                // 退出学生管理系统入口；
			/*###############################################################
			####################   退出学生管理系统模块    ####################*/


			printf("是否保存以上操作， Y or N ? ");
			state = getchar();
			getchar();                                   // 消除本次的回车键；
			if (state == 'y' || state == 'Y')                // 加一个保存界面；
			{
				fp = fopen("data.dat", "wb");
				/*###############################################################*/
				if (NULL == fp)                              // 判断文件是否打开失败；
				{
					printf("Open files error\n");
					exit(-1);
				}
				/*###############################################################*/
				Ftemp = head;
				while (Ftemp->next != NULL)                   // 写文件的判断条件；
				{
					fwrite((void*)Ftemp, sizeof(STU_INFOR), 1, fp);
					Ftemp = Ftemp->next;
				}
				fwrite((void*)Ftemp, sizeof(STU_INFOR), 1, fp);  // 把指针的最后一个写入的文件中；            
				fclose(fp);
				printf("恭喜你，保存成功。\n");
			}
			printf("按任意键继续！\n");
			getchar();
			exit(0);
			break;
			/*###############################################################
			############    当输入的不是有效的数字模块   ###################*/
		default:printf("你输入的有误，按任意键返回主界面\n ");
			getchar();
		}
	} while (1);
	/*################################################################
	###################     到此,整个循环结束    #####################
	###############################################################*/
	return 0;
}