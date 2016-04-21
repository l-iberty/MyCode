/* *
 * 十三张红桃里有A 2 3 4 5 6 7 8 9 10 J Q K
 * 十三张黑桃里有A 2 3 4 5 6 7 8 9 10 J Q K
 * 十三张梅花里有A 2 3 4 5 6 7 8 9 10 J Q K
 * 十三张方块里有A 2 3 4 5 6 7 8 9 10 J Q K
 * */

#include <stdio.h>
#include <stdlib.h>
#define N 21
int poker[53];/* poker[]记录点数 */

void display(); /* 将牌号转换为点数 */
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
	/* point为点数 */

	/* i为牌号 */
	for (i = 1;i <= 52;i++)
	{
		point = i % 13;
		if (point > 10 || point == 0)/* point>10 --> J,Q;point==0 --> K */
			point = 10; /* J,Q,K算10点 */
		if (point == 1)
			point = 11; /* A算11点 */
		poker[i] = point;
	}

	/* i为计数变量 */
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
	/* poker[]下标随机取得,其值为k */
	unsigned seed;

	sum = countA = 0;
	/* for控制游戏轮数 */
	for ( good = fail = 0,n = 0;n < 10;n++ )
	{
		sum = countA = 0;

		printf("\nseed: ");
		scanf_s("%u", &seed);
		srand(seed);

		do {
			/* 内层循环:一直抽牌,直到点数大于或等于N */
			do {
				k = 1 + rand() % (52 - 1 + 1);
				rpoint = poker[k];

				if (rpoint == 11)
					countA++;
				sum += rpoint;
				printf("\nYou get %d, total = %d", rpoint, sum);
			} while (sum < N);

			/* 对总点数进行判断 */
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
					flag = 1; /* 既没输也没赢,进入下一轮循环接着玩 */
			}
		} while (flag == 1);
	}
	
	printf("\nGood -- %d  Fail -- %d\n", good, fail);
}