/* *
 * ʮ���ź�������A 2 3 4 5 6 7 8 9 10 J Q K
 * ʮ���ź�������A 2 3 4 5 6 7 8 9 10 J Q K
 * ʮ����÷������A 2 3 4 5 6 7 8 9 10 J Q K
 * ʮ���ŷ�������A 2 3 4 5 6 7 8 9 10 J Q K
 * */

#include <stdio.h>
#include <stdlib.h>
#define N 21
int poker[53];/* poker[]��¼���� */

void display(); /* ���ƺ�ת��Ϊ���� */
void begin();

int main()
{
	display();
	begin();

	return 0;
}

void display()
{
	int i, point;
	/* pointΪ���� */

	/* iΪ�ƺ� */
	for (i = 1;i <= 52;i++)
	{
		point = i % 13;
		if (point > 10 || point == 0)/* point>10 --> J,Q;point==0 --> K */
			point = 10; /* J,Q,K��10�� */
		if (point == 1)
			point = 11; /* A��11�� */
		poker[i] = point;
	}

	/* iΪ�������� */
	for (i = 1;i <= 52;i++)
	{
		printf("%2d ", poker[i]);
		if (i % 13 == 0)
			printf("\n");
	}
}

void begin()
{
	int rpoint, sum, n, k, countA, good, fail, flag;
	/* poker[]�±����ȡ��,��ֵΪk */
	unsigned seed;

	sum = countA = 0;
	/* for������Ϸ���� */
	for ( good = fail = 0,n = 0;n < 10;n++ )
	{
		sum = countA = 0;

		printf("\nseed: ");
		scanf_s("%u", &seed);
		srand(seed);

		do {
			/* �ڲ�ѭ��:һֱ����,ֱ���������ڻ����N */
			do {
				k = 1 + rand() % (52 - 1 + 1);
				rpoint = poker[k];

				if (rpoint == 11)
					countA++;
				sum += rpoint;
				printf("\nYou get %d, total = %d", rpoint, sum);
			} while (sum < N);

			/* ���ܵ��������ж� */
			if (sum <= 21)
			{
				printf("\nGood! %d\n", sum);
				good++;
				flag = 0;
			}
			else if (countA == 0) {
				printf("\nFail! %d\n", sum);
				fail++;
				flag = 0;
			}
			else {
				sum -= 10;
				countA--;
				if (sum >= N) {
					printf("\nGood! %d\n", sum);
					good++;
					flag = 0;
				}
				else
					flag = 1; /* ��û��ҲûӮ,������һ��ѭ�������� */
			}
		} while (flag == 1);
	}
	
	printf("\nGood -- %d  Fail -- %d\n", good, fail);
}