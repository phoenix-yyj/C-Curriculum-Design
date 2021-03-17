typedef struct book_infor BOOK_INFOR;
struct book_infor {
	int  bookNum;
	char bookName[20];
	float  bookPrice;
	char bookPublisher[40];
	struct book_infor* next;
};
void ScreenDisplay(void);                                            // 界面函数；
BOOK_INFOR* Setup_Infor(void);                                       // 建立链表函数；
BOOK_INFOR* Dle_Infor(BOOK_INFOR* head, int bookNum);                // 删除书籍信息函数；
BOOK_INFOR* Mod_Infor(BOOK_INFOR* head, BOOK_INFOR* modify);         // 修改书籍信息函数；
BOOK_INFOR* Input_Infor(BOOK_INFOR* phead, BOOK_INFOR* newstruct);   // 录入书籍信息函数；
void Check_Infor(BOOK_INFOR* phead, int bookNum);                    // 查看书籍信息函数；
void Display_Infor(BOOK_INFOR* phead);                               // 显示所有信息函数；
void BubbleSort(BOOK_INFOR* head);                                   // 自动排序