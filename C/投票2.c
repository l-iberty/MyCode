#include <stdio.h>
/* �ö�ά����ʵ�� */ 

int main()
{
	char *name[] = {"Li", "Zhang", "Wang"};
	int count[3][3] = {0};
	/* ��ά������б���name[]�е�������Ӧ,�����б꼴����
	   ��Ӧ�ĺ�ѡ��,�����б꼴���ʶ�Ӧ��ѡ�˵ļ����� */ 
	
	int i, j, s, error = 0;
	char person, dept;
	
	for (i = 1;i <= 10;i++)
	{
		scanf("%c%c", &person, &dept);
		/* A,B,C��ʾ�ֱ��L,Z,WͶƱ;1,2,3��ʾͶƱ�����Ե�Ⱥ��:teacher,student,worker */
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
