/**
 * �����ɸ�����ɾ��������λ������ʣ�µ������°������У�
 * ��˷����������ʣ�µ���ԭ�����ڵ�λ��
 **/
 
#include <stdio.h>
#include <stdlib.h>

struct link {
	int order;
	int flag;
	struct link *next;
};

int main()
{
	int i, n, r, count; // r���������
	struct link *head, *new, *tmp, *current; // tmp�ڴ���ʱʹ��,current�����ʱʹ��

	printf("n=? ");
	scanf_s("%d", &n);

	new = (struct link*)malloc(sizeof(struct link));
	new->order = 1;
	new->flag = 1;
	/* �����ڵ� */

	head = new; /* ����ͷָ�� */
	tmp = head;

	for (i = 2;i <= n;i++)
	{
		new = (struct link*)malloc(sizeof(struct link));
		new->order = i; /* ��Ϊ��һ���ڵ��order�Ѿ�����Ϊ1 */
		new->flag = 1;

		tmp->next = new;
		tmp = new;
	}
	new->next = head;
	/* ѭ����������� */
	/* ��ʱnew,tmpָ�����һ���ڵ�,���˶���,���ͷ�֮ */
	tmp = new = NULL;

	count = 0;
	r = 0;
	current = head;
	do
	{
		if (current->flag != 0)
			r++;

		/* ����rΪ������û���޳�(flag != 0),������һ��
		   �����н����޳� */
		if (r % 2 != 0 && current->flag != 0)
		{
			printf("%d ", current->order);
			current->flag = 0;
			if (current->next == head)
				r = 0;
			count++;
		}
		current = current->next;
	} while (count != n);

	return 0;
}