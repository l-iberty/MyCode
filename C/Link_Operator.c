#include <stdio.h>
#include <stdlib.h>

struct demo* add(struct demo *head, struct demo *new, int inData);
void display(struct demo *head);
int size(struct demo *head);
struct demo* delFisrt(struct demo *head);
struct demo* delMiddle(struct demo *head, int index);
struct demo* delLast(struct demo *head);

struct demo {
	int data;
	struct demo *next;
};

int main()
{
	int i;
	struct demo *head, *new;
	head = NULL;

	for (i = 10;i <= 100;i+=10) {
		new = (struct demo*)malloc(sizeof(struct demo));
		head = add(head, new, i);
	}

	display(head);
	printf("\nThe number of linklist: %d\n\n", size(head));

	delMiddle(head, 3);
	display(head);
	printf("\nThe number of linklist: %d\n\n", size(head));

	head = delFisrt(head);
	display(head);
	printf("\nThe number of linklist: %d\n\n", size(head));

	delLast(head);
	display(head);
	printf("\nThe number of linklist: %d\n\n", size(head));

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
		printf("%d ", current->data);
		current = current->next;
	}
}

struct demo* delFisrt(struct demo *head)
{
	struct demo *tmp;
	tmp = head;
	head = head->next;
	free(tmp);
	return head;
}

struct demo* delLast(struct demo *head)
{
	struct demo *tmp1, *tmp2;/* tmp1标记倒数第二个最后一个,tmp2标记最后一个 */
	tmp1 = head;
	tmp2 = tmp1->next;
	while (tmp2->next != NULL){
		tmp1 = tmp2;
		tmp2 = tmp1->next;
	}
	tmp1->next = NULL;
	free(tmp2);

	return head;
}

struct demo* delMiddle(struct demo *head, int index)
{
	int i = 2;
	struct demo *tmp1, *tmp2;
    /* tmp1标记待删除元素的前一个,tmp2标记待删除元素 */
	tmp1 = head;
	tmp2 = tmp1->next;
	
	while (i < index) {
		tmp1 = tmp2;
		tmp2 = tmp1->next;
		i++;
	}
	tmp1->next = tmp2->next;
	free(tmp2);

	return head;
}