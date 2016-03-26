#include <stdio.h>
/* 用二维数组实现 */ 

int main()
{
	char *name[] = {"Li", "Zhang", "Wang"};
	int count[3][3] = {0};
	/* 二维数组的行标与name[]中的人名对应,访问行标即访问
	   对应的候选人,访问列标即访问对应候选人的计数器 */ 
	
	int i, j, s, error = 0;
	char person, dept;
	
	for (i = 1;i <= 10;i++)
	{
		scanf("%c%c", &person, &dept);
		/* A,B,C表示分别给L,Z,W投票;1,2,3表示投票者来自的群体:teacher,student,worker */
		if ((person >= 'A' && person <= 'C') && (dept >= '1' && dept <= '3'))
			count[person - 'A'][dept - '1']++;
		else
			error++;
	}
	
	printf("Candidate  Teacher Student Worker  Total\n");

	for (i = 0;i < 3;i++)
	{
		printf("%9s: ", name[i]);
		for (j = s = 0;j < 3;j++)
		{
			printf("%-7d ", count[i][j]);
			s += count[i][j];
		}
		printf("%-7d\n", s);
	}
	printf("error -- %d\n", error);

	return 0;
}
