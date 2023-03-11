#include "Func.h"

int main()	{
	FILE* f1 = fopen("Info.txt", "r");
	FILE* f2 = fopen("Out.txt", "w+");
	
	List Head;
	List* list = ReadList(f1, &Head);


	list = SortList(list);
	fprintf(f2, "\nSorted list:\n");
	PrintList(f2, list);
	fprintf(f2, "\n");

	list = ClearList(f2, list);
	PrintList(f2, list);
	fprintf(f2, "\n");


	B el = Add_New_Struct();
	list=AddToSortedList(list, el);
	PrintList(f2, list);
}	