#include <iostream>
using namespace std;

typedef struct Demo* List;

List createList();
int isEmpty(List L);
void addElement(int x, List L);
void disposeList(List L);
void display(List L);
void printLots(List L, List P);

struct Demo {
	int element;
	struct Demo *next;
};

List createList() {
	List L;

	L = new struct Demo;
	if (L == NULL)
		return NULL;
	else {
		L->next = NULL;
		return L;
	}
}

int isEmpty(List L) {
	return L->next == NULL;
}

void addElement(int x, List L) {
	List newNode, current;

	newNode = new struct Demo;
	if (newNode == NULL)
		cout << "Error" << endl;
	else {
		current = L;
		while (current->next != NULL)
			current = current->next;

		newNode->element = x;
		newNode->next = NULL;
		current->next = newNode;
	}
}

void disposeList(List L) {
	List current;

	if (isEmpty(L))
		cout << "Error" << endl;
	else {
		current = L;
		while (current != NULL) {
			L = L->next;
			delete current;
			current = L;
		}
	}
}

void display(List L) {
	List current;
	if (isEmpty(L))
		cout << "Empty List" << endl;
	else {
		current = L->next;
		while (current != NULL) {
			cout << current->element << " ";
			current = current->next;
		}
	}
}

void printLots(List L, List P) {
	List Lpos, Ppos;
	int count = 1;

	Lpos = L->next;
	Ppos = P->next;
	while (Lpos != NULL && Ppos != NULL) {
		if (Ppos->element == count++) {
			cout << Lpos->element << " ";
			Ppos = Ppos->next;
		}
		Lpos = Lpos->next;
	}
}

int main() {
	List L, P;
	int i, x;

	L = createList(), P = createList();
	if (L == NULL && P == NULL) {
		cout << "Error" << endl;
		return 1;
	}

	cout << "L:" << endl;
	for (i = 0; i < 10; i++) {
		cin >> x;
		addElement(x, L);
	}
	cout << "P:" << endl;
	for (i = 0; i < 4; i++) {
		cin >> x;
		addElement(x, P);
	}

	cout << endl << "L: ";
	display(L);
	cout << endl << "P: ";
	display(P);

	cout << endl << "PrintLots(L, P): ";
	printLots(L, P);
	disposeList(L);
	disposeList(P);
	return 0;
}