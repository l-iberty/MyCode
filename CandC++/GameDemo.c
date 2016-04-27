#include <stdio.h>
#include <stdlib.h>

int totalpoint(int seed);

int main()
{
	int prev_sum, tmp_sum, round, flag, flag1 = 1;
	unsigned int seed;

	for (round = 1, flag = 1;flag;round++) {
		if (round == 1) {
			printf("seed? ");
			scanf_s("%u", &seed);

			prev_sum = totalpoint(seed);
			printf("You got %d point!\n", prev_sum);

			if (prev_sum == 7 || prev_sum == 11) {
				printf("Won!\n");
				flag = 0;
			}
			else if (prev_sum == 2 || prev_sum == 3 || prev_sum == 12) {
				printf("Lost!\n");
				flag = 0;
			}
		}
		if (round > 1) {
			do {
				printf("\nseed? ");
				scanf_s("%u", &seed);

				tmp_sum = totalpoint(seed);
				printf("You got %d point!\n", tmp_sum);
				
				if (tmp_sum == prev_sum) {
					printf("Won!\n");
					flag = flag1 = 0;
				}
				else if (tmp_sum == 7) {
					printf("Lost!\n");
					flag = flag1 = 0;
				}
			} while (flag1);
		}
	}
}

int totalpoint(int seed)
{
	int i, sum, rpoint;
	srand(seed);
	for (i = 0, sum = 0;i < 2;i++) {
		rpoint = 1 + rand() % (6 - 1 + 1);
		printf("<%d>: %d\n", i+1, rpoint);
		sum += rpoint;
	}

	return sum;
}