#define _CRT_SECURE_NO_WARNINGS
#define LEN 100
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct book {
	char author[50];
	char name[50];
	int year;
	int pages;
	int price;
}B;

typedef struct ListNode {
	B Data;
	struct ListNode* Next;
} List;


B Fill_Book(char* str);
List* ReadList(FILE * f1, List* Head);
void Swap(List* a, List* b);
List* SortList(List* head);
int IsCorrect(List* el, int maxPages);
double Sum(FILE * f2, List* el);
List* ClearList(FILE * f2, List* head);
void PrintList(FILE * f2, List* head);
List* AddToSortedList(List* head, B el);
B Add_New_Struct();