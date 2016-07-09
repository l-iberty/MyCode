#include <stdio.h>
#include <stdlib.h>

struct demo* add(struct demo *head, struct demo *new, int inData);
void display(struct demo *head);
int size(struct demo *head);
struct demo* findPrevious(struct demo *head, int inData);
struct demo* delFisrt(struct demo *head);
void delOthers(struct demo *head, int inData);
void insert(struct demo *head, int inData, int newData);
/* 将newData插入到inData位置，并将inData后移 */

struct demo {
	int data;
	struct demo *next;
};

int main()
{
	int i, inData;
	struct demo *head, *new;
	head = NULL;

	for (i = 10; i <= 100; i += 10) {
		new = (struct demo*)malloc(sizeof(struct demo));
		head = add(head, new, i);
	}

	display(head);
	printf_s("\nThe number of linklist: %d\n", size(head));

	insert(head, 30, 35);
	display(head);
	printf_s("\nThe number of linklist: %d\n", size(head));

	printf_s("\nEnter the element needed deleting: ");
	scanf_s("%d", &inData);
	delOthers(head, inData);
	printf_s("\nAfter deleting...\n");
	display(head);
	printf_s("\nThe number of linklist: %d\n", size(head));


	head = delFisrt(head);
	printf_s("\nAfter deleting the first one...\n");
	display(head);
	printf_s("\nThe number of linklist: %d\n", size(head));

	return 0;
}

struct demo* add(struct demo *head, struct demo *new, int inData)
{
	struct demo *current;
	new->data = inData;
	new->next = NULL;

	if (head == NULL) {
		head = new;
		return head;
	}

	current = head;
	while (current->next != NULL)
		current = current->next;

	current->next = new;
	return head;
}

int size(struct demo *head)
{
	struct demo *current;
	int count = 0;

	current = head;
	while (current != NULL) {
		current = current->next;
		count++;
	}

	return count;
}

void display(struct demo *head)
{
	struct demo *current;

	current = head;
	while (current != NULL) {
		printf_s("%d ", current->data);
		current = current->next;
	}
}

struct demo* findPrevious(struct demo *head, int inData) {
	struct demo *position;
	position = head;

	while (position->next != NULL && position->next->data != inData)
		position = position->next;

	return position;
}

struct demo* delFisrt(struct demo *head)
{
	struct demo *tmp;
	tmp = head;
	head = head->next;
	free(tmp);
	return head;
}

void delOthers(struct demo *head, int inData) {
	struct demo *prev, *tmp;//tmp指向待删除元素
	prev = findPrevious(head, inData);
	
	if (prev->next != NULL) {
		tmp = prev->next;
		prev->next = tmp->next;
		free(tmp);
	}
}

void insert(struct demo *head, int inData, int newData) {
	struct demo *new, *prev, *tmp;
	new = (struct demo*)malloc(sizeof(struct demo));
	if (new == NULL) {
		printf_s("Error");
		return;
	}
	new->data = newData;

	prev = findPrevious(head, inData);
	tmp = prev->next;
	prev->next = new;
	new->next = tmp;
}