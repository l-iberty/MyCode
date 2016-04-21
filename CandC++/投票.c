#include <stdio.h>

struct candidate {
	char name[10];
	int count[3];
};
int main()
{
	int i, j, s, error = 0;
	char person, dept;
	struct candidate a[3] = {
		{ "Li",{ 0 } },
		{ "Zhang",{ 0 } },
		{ "Wang",{ 0 } } };

	for (i = 1;i <= 10;i++)
	{
		scanf("%c%c", &person, &dept);
		/* A,B,C表示分别给L,Z,W投票;1,2,3表示投票者来自的群体:teacher,student,worker */
		if ((person >= 'A' && person <= 'C') && (dept >= '1' && dept <= '3'))
			a[person - 'A'].count[dept - '1']++;
		else
			error++;
	}
	printf("Candidate  Teacher Student Worker  Total\n");

	for (i = 0;i < 3;i++)
	{
		printf("%9s: ", a[i].name);
		for (j = s = 0;j < 3;j++)
		{
			printf("%-7d ", a[i].count[j]);
			s += a[i].count[j];
		}
		printf("%-7d\n", s);
	}
	printf("error -- %d\n", error);

	return 0;
}
