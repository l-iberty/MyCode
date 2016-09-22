#include "SinglyLinkedList.h"

int main() {
	List L;
	int i;

	L = createList();
	if (L == NULL) {
		printf_s("Error");
		return 1;
	}

	printf_s("First, is List Empty? %d\n", isEmpty(L));
	for (i = 0; i < 5; i++)
		addElement(i + 1, L);
	display(L);

	printf_s("\nInsert(L, 1, 0): ");
	insert(L, 1, 0);
	display(L);

	printf_s("\nInsert(L, 3, 10): ");
	insert(L, 3, 10);
	display(L);

	printf_s("\nInsert(L, 5, 6): ");
	insert(L, 5, 6);
	display(L);

	printf_s("\nDelete the first: ");
	delFirst(L);
	display(L);

	printf_s("\nDelOthers(L,10): ");
	delOthers(L, 10);
	display(L);

	printf_s("\nDelOthers(L,5): ");
	delOthers(L, 5);
	display(L);

	printf_s("\nDelOthers(L,1): ");
	delOthers(L, 1);
	display(L);

	printf_s("\nDelOthers(L,0): ");
	delOthers(L, 0);
	display(L);

	disposeList(L);
}