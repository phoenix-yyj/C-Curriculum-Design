#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include "sourse.h"
void BubbleSort1(STU_INFOR* head)
{
    STU_INFOR* cur = NULL;
    STU_INFOR* teil = NULL;
    cur = head->next;
    while (cur != teil) {
        while (cur->next != teil) {
            if (cur->stuScore1 < cur->next->stuScore1) {
                float temp = cur->stuScore1;
                cur->stuScore1 = cur->next->stuScore1;
                cur->next->stuScore1 = temp;
            }
            cur = cur->next;
        }
        teil = cur;
        cur = head->next;
    }
}
void BubbleSort2(STU_INFOR* head)
{
    STU_INFOR* cur = NULL;
    STU_INFOR* teil = NULL;
    cur = head->next;
    while (cur != teil) {
        while (cur->next != teil) {
            if (cur->stuScore2 < cur->next->stuScore2) {
                float temp = cur->stuScore2;
                cur->stuScore2 = cur->next->stuScore2;
                cur->next->stuScore2 = temp;
            }
            cur = cur->next;
        }
        teil = cur;
        cur = head->next;
    }
}
void BubbleSort3(STU_INFOR* head)
{
    STU_INFOR* cur = NULL;
    STU_INFOR* teil = NULL;
    cur = head->next;
    while (cur != teil) {
        while (cur->next != teil) {
            if (cur->stuScore3 < cur->next->stuScore3) {
                float temp = cur->stuScore3;
                cur->stuScore3 = cur->next->stuScore3;
                cur->next->stuScore3 = temp;
            }
            cur = cur->next;
        }
        teil = cur;
        cur = head->next;
    }
}