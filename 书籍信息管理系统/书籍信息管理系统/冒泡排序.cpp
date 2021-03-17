#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include "sourse.h"
void BubbleSort(BOOK_INFOR* head)
{
	BOOK_INFOR* cur = NULL;
	BOOK_INFOR* teil = NULL;
	cur = head->next;
	while (cur != teil) {
		while (cur->next != teil) {
			if (cur->bookNum > cur->next->bookNum) {
				float temp = cur->bookNum;
				cur->bookNum = cur->next->bookNum;
				cur->next->bookNum = temp;
			}
			cur = cur->next;
		}
		teil = cur;
		cur = head->next;
	}
}