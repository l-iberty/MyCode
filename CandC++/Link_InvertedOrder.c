#include <stdio.h>
#include <stdlib.h>
#define N 10

struct link {
	int data;
	struct link *next;
};

int main()
{
	int i;
	struct link *head, *new, *tmp, *current, *prev;
	/* new��tmp���ڴ�������,current��prev���ڷ�ת���� */

	/* ���� */
	new = (struct link*)malloc(sizeof(struct link));
	head = new;
	head->data = 1;
	tmp = head;

	for (i = 2;i <= N;i++)
	{
		new = (struct link*)malloc(sizeof(struct link));
		new->data = i;

		tmp->next = new;
		tmp = new;
	}
	tmp->next = NULL;
	tmp = new = NULL;

	/* ��� */
	printf("Previously...\n");
	current = head;
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}

	/* ��ת */
	prev = NULL;
	do {
		current = head;
		head = head->next;
		current->next = prev;
		prev = current;
	} while (head->next != NULL);
	head->next = prev;
	prev = current = NULL;

	/* ��� */
	printf("\nNow...\n");
	current = head;
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}

	return 0;
}