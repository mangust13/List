#include "Func.h"

B Fill_Book(char* str) {
	B result;
	char* pw;

	pw = strtok(str, ","); strcpy(result.author, pw);
	pw = strtok(NULL, ","); strcpy(result.name, pw);
	pw = strtok(NULL, ","); result.year = atoi(pw);
	pw = strtok(NULL, ","); result.pages = atoi(pw);
	pw = strtok(NULL, ","); result.price = atoi(pw);
	return result;
}

B Add_New_Struct() {
	B res;
	char aut[LEN], name[LEN];
	int year, pages, price;
	printf("Enter author: ");
	gets(aut);
	strcpy(res.author, aut);
	printf("Enter name: ");
	gets(name);
	strcpy(res.name, name);
	printf("Enter year: ");
	scanf("%d",&year);
	res.year = year;
	printf("Enter pages: ");
	scanf("%d", &pages);
	res.pages = pages;
	printf("Enter price: ");
	scanf("%d", &price);
	printf("\n");
	res.price = price;
	return res;
}


List* ReadList(FILE* f1, List* Head) {

	List* p = Head;
	char str[LEN];
	fgets(str, LEN, f1);
	Head->Data = Fill_Book(str);
	while (fgets(str, LEN, f1)) {

		List* NewNode = malloc(sizeof(List));
		Head->Next = NewNode;
		NewNode->Data = Fill_Book(str);
		Head = NewNode;
	}
	Head->Next = NULL;
	fclose(f1);
	return p;
}


void Swap(List* a, List* b) {
	B temp = a->Data;
	a->Data = b->Data;
	b->Data = temp;
}


List* SortList(List* head) {

	List* q = head;
	while (q) {
		List* p = q->Next;
		List* max = q;

		while (p)
		{
			if (p->Data.year > max->Data.year)
			{
				max = p;
			}
			p = p->Next;
		}

		Swap(q, max);
		q = q->Next;
	}
	return head;
}


int IsCorrect(List* el, int avrPages) {
	return el->Data.pages > avrPages;
}



double Sum(FILE * f2, List* el) {
	int sum = 0, count = 0;;
	if (el == NULL) {
		fprintf(f2, "Error: root is NULL");
		return -1;
	}

	List* z = el;
	while (z) {
		++count;
		z = z->Next;
	}

	List* q = el;
	while (q) {
		sum += q->Data.pages;
		q = q->Next;
	}
	fprintf(f2, "Average amount of pages is: %d\n\n", sum / count);
	return sum / count;
}



List* ClearList(FILE * f2, List* head) {
	double avr = Sum(f2, head);
	while (!IsCorrect(head, avr)) //шукаємо перший елемент, що відповідає умові
	{
		List* temp = head;
		head = head->Next;
	}

	List* p = head;
	while (p->Next) {
		if (!IsCorrect(p->Next, avr)) {
			List* temp = p->Next;
			p->Next = p->Next->Next;
			free(temp);
		}

		else p = p->Next;
	}

	return head;
}



void PrintList(FILE *f2, List* p) {
	fprintf(f2, "|Autor| |Name| |Year| |Pages| |Price|\n");
	while (p) {
		fprintf(f2, "|%-25s| |%-25s| |%-4d| |%-4d| |%-4d|\n", p->Data.author, p->Data.name, p->Data.year, p->Data.pages, p->Data.price);
		p = p->Next;
	}
}


List* AddToSortedList(List* head, B el) {
	List* NewNode = malloc(sizeof(List));
	NewNode->Data = el;

	if (head->Data.year < el.year) {
		NewNode->Next = head;
		head = NewNode;
		return head;
	}

	else {
		List *tmp= head, *tmp2 = head;
		int k = 0;

		for (; ((tmp2->Next) && tmp2->Data.year > el.year); ++k, tmp2 = tmp2->Next);

		for (int i = 0; i < k-1; ++i){
			tmp = tmp->Next;
		}

		if (tmp2->Next) {
			NewNode->Next = tmp->Next;
			tmp->Next = NewNode;
		}

		else {
			NewNode->Next = NULL;
			tmp2->Next = NewNode;
		}

		return head;
	}
}