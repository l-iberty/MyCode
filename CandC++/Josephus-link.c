/* 循环链表解决约瑟夫问题 */
/* n个人围成一圈,按顺时针方向编号1,2,...,n,
 * 从1号开始顺时针报数,每数到第m个人就走出
 * 圆圈,下一个人重新开始报数按先后顺序输出
 * 圈内走出的人的编号.(m可以小于n)
 */

#include <stdio.h>
#include <stdlib.h>

struct link {
	int data;
	struct link *next;
};

int main()
{
	int i, key, n, r, count; // r为报数器
	struct link *head, *new, *tmp, *current; // tmp在创建时使用,current在输出时使用

	printf("n,key=? ");
	scanf_s("%d %d", &n, &key); // 总数为n,报数为m

	new = (struct link*)malloc(sizeof(struct link));
	new->data = 1;
	/* 创建节点 */

	head = new; /* 定义头指针 */
	tmp = head;

	for (i = 2;i <= n;i++)
	{
		new = (struct link*)malloc(sizeof(struct link));
		new->data = i; /* 因为第一个节点的data已经设置为1 */

		tmp->next = new;
		tmp = new;
	}
	new->next = head;
	/* 循环链表构建完成 */
	/* 此时new,tmp指向最后一个节点,此乃多余,可释放之 */
	tmp = new = NULL;

	/* 输出循环链表
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
			r++; /* 顺着报数 */
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