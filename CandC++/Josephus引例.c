/**
 * 有若干个数，删除奇数号位的数，剩下的数重新按序排列，
 * 如此反复，求最后剩下的数原来所在的位置
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
	int i, n, r, count; // r是排序变量
	struct link *head, *new, *tmp, *current; // tmp在创建时使用,current在输出时使用

	printf("n=? ");
	scanf_s("%d", &n);

	new = (struct link*)malloc(sizeof(struct link));
	new->order = 1;
	new->flag = 1;
	/* 创建节点 */

	head = new; /* 定义头指针 */
	tmp = head;

	for (i = 2;i <= n;i++)
	{
		new = (struct link*)malloc(sizeof(struct link));
		new->order = i; /* 因为第一个节点的order已经设置为1 */
		new->flag = 1;

		tmp->next = new;
		tmp = new;
	}
	new->next = head;
	/* 循环链表构建完成 */
	/* 此时new,tmp指向最后一个节点,此乃多余,可释放之 */
	tmp = new = NULL;

	count = 0;
	r = 0;
	current = head;
	do
	{
		if (current->flag != 0)
			r++;

		/* 序数r为奇数且没被剔除(flag != 0),才在新一轮
		   排序中将其剔除 */
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