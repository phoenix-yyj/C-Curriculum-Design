typedef struct stu_infor STU_INFOR;
struct stu_infor {
	int  stuNum;
	char stuName[20];
	float  stuScore1;
	float  stuScore2;
	float  stuScore3;
	struct stu_infor* next;
};
void ScreenDisplay(void);                                          // ���溯����
STU_INFOR* Setup_Infor(void);                                      // ������������
STU_INFOR* Dle_Infor(STU_INFOR* head, int stuNum);                 // ɾ��ѧ����Ϣ������
STU_INFOR* Mod_Infor(STU_INFOR* head, STU_INFOR* modify);          // �޸�ѧ����Ϣ������
STU_INFOR* Input_Infor(STU_INFOR* phead, STU_INFOR* newstruct);    // ¼��ѧ����Ϣ������
void Check_Infor(STU_INFOR* phead, int stuNum);                    // �鿴ѧ����Ϣ������
void Display_Infor(STU_INFOR* phead);                              // ��ʾ������Ϣ������
void BubbleSort1(STU_INFOR* head);                                  // ����
void BubbleSort2(STU_INFOR* head);
void BubbleSort3(STU_INFOR* head);