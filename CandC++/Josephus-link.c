/* ѭ��������Լɪ������ */
/* n����Χ��һȦ,��˳ʱ�뷽����1,2,...,n,
 * ��1�ſ�ʼ˳ʱ�뱨��,ÿ������m���˾��߳�
 * ԲȦ,��һ�������¿�ʼ�������Ⱥ�˳�����
 * Ȧ���߳����˵ı��.(m����С��n)
 */

#include <stdio.h>
#include <stdlib.h>

struct link {
	int data;
	struct link *next;
};

int main()
{
	int i, key, n, r, count; // rΪ������
	struct link *head, *new, *tmp, *current; // tmp�ڴ���ʱʹ��,current�����ʱʹ��

	printf("n,key=? ");
	scanf_s("%d %d", &n, &key); // ����Ϊn,����Ϊm

	new = (struct link*)malloc(sizeof(struct link));
	new->data = 1;
	/* �����ڵ� */

	head = new; /* ����ͷָ�� */
	tmp = head;

	for (i = 2;i <= n;i++)
	{
		new = (struct link*)malloc(sizeof(struct link));
		new->data = i; /* ��Ϊ��һ���ڵ��data�Ѿ�����Ϊ1 */

		tmp->next = new;
		tmp = new;
	}
	new->next = head;
	/* ѭ����������� */
	/* ��ʱnew,tmpָ�����һ���ڵ�,���˶���,���ͷ�֮ */
	tmp = new = NULL;

	/* ���ѭ������
	current = head;
	for (i = 0;i < n;i++)
	{
		printf("%d ", current->data);
		current = current->next;
	} */

	r = 0;
	count = 0;
	current = head;
	do
	{
		if (current->data != 0)
			r++; /* ˳�ű��� */
		if (r == key)
		{
			printf("%d ", current->data);
			current->data = 0;
			r = 0;
			count++;
		}
		current = current->next;
	} while (count != n);

	return 0;
}