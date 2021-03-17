typedef struct book_infor BOOK_INFOR;
struct book_infor {
	int  bookNum;
	char bookName[20];
	float  bookPrice;
	char bookPublisher[40];
	struct book_infor* next;
};
void ScreenDisplay(void);                                            // ���溯����
BOOK_INFOR* Setup_Infor(void);                                       // ������������
BOOK_INFOR* Dle_Infor(BOOK_INFOR* head, int bookNum);                // ɾ���鼮��Ϣ������
BOOK_INFOR* Mod_Infor(BOOK_INFOR* head, BOOK_INFOR* modify);         // �޸��鼮��Ϣ������
BOOK_INFOR* Input_Infor(BOOK_INFOR* phead, BOOK_INFOR* newstruct);   // ¼���鼮��Ϣ������
void Check_Infor(BOOK_INFOR* phead, int bookNum);                    // �鿴�鼮��Ϣ������
void Display_Infor(BOOK_INFOR* phead);                               // ��ʾ������Ϣ������
void BubbleSort(BOOK_INFOR* head);                                   // �Զ�����