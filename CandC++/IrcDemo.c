#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int isIrc(const char *msg);
int label(char *msg);
void sort(char *msg[], int n);
void show(char *msg[], int n);

int main()
{
	FILE *fp;
	int ch, i, j, r, t, k, s;
	int strn, ircn, time_label, newircn;
	/* strnΪ������, ircnΪ��Ч�������, time_labelΪʱ���ǩ����*/
	char str[100][100], time_irc_str[100][100], time_str[100][100], irc_str[100][100],
		new_time_irc_str[100][100], *p[100];
	if ((fp = fopen("C:\\Users\\len\\Desktop\\С����.Irc", "r")) == NULL) {
		fprintf(stderr, "error\n");
		exit(1);
	}

	i = 0;
	while ((ch = fgetc(fp)) != EOF) {
		j = 0;
		while (ch != '\n') {
			// i�����, j���ÿ�е�ÿ���ַ�
			str[i][j++] = ch;
			ch = fgetc(fp);
		}
		str[i++][j] = '\0';
		/* �˳��ڲ�whileʱ, chΪ'\n', ����һ�ֽ������while������������Ϊ��һ�еĵ�һ���ַ� */
	}
	strn = i;
	fclose(fp);
	/* for (j = 0;j < i;j++) puts(str[j]); �����ʴ� */

	/* ȡ��ʱ���ʴ� */
	for (i = j = 0;i < strn;i++) {
		if (isIrc(str[i])) {
			strcpy(time_irc_str[j++], str[i]);
			// puts(time_irc_str[j - 1]);
		}
	}
	ircn = j;

	/* ȡ��ʱ���ʴ��е�ʱ���ǩ�͸�� */
	for (i = k = s = 0;i < ircn;i++) {
		// i��ʱ���ʵ��б��
		// k��ʱ���ǩ���б��
		time_label = label(time_irc_str[i]);
		for (j = r = 0;r < time_label;r++, j += 10) {
			/* j+=10, ����ȡ������ڸ��е���һ��ʱ���ǩ */
			for (t = 0;t < 10;t++) time_str[k][t] = time_irc_str[i][t + j];
			time_str[k++][t] = '\0';
			//puts(time_str[k-1]);
		}
		// ��һ��for����ʱ���ʴ�
		// �ڶ���for����ÿ��ʱ���ʴ�������ʱ���ǩ
		// ������for��ÿ��ʱ���ǩ����time_str[][]

		t = 10 * time_label;
		// ÿ��ʱ���ǩ��10���ַ�, �ɴ�����ʱ���ǩ��ȡ����ĸ��
		// ע������������ʱ��������
		for (j = t, r = 0;time_irc_str[i][j] != '\0';j++, r++) {
			irc_str[i][r] = time_irc_str[i][j];
		}
		irc_str[i][r] = '\0';
		//puts(irc_str[i]);

		/* ��ʱ���ǩ�͸��ƴ�ӳ��µ�ʱ���ʴ� */
		for (j = 0;j < time_label;j++, s++) {
			strcpy(new_time_irc_str[s], time_str[s]);
			strcat(new_time_irc_str[s], irc_str[i]);
			/* ����ÿ��ȷ����i��, ��Ҫ����ƴ�ӵ����ٸ�ʱ���ǩ�����ɸ���
               ��ʱ���ǩ������. �����for��, ѭ������������ÿ�и�ʵ���
			   ������: s����µ�ʱ���ʴ�����, ÿ��ȷ����i���м���ʱ��
			   ��ǩ�͵������� */
			//puts(new_time_irc_str[s]);
		}
		newircn = s;
	}

	for (i = 0;i < newircn;i++) {
		p[i] = new_time_irc_str[i];
		//puts(p[i]);
	}
	sort(p, newircn);
	show(p, newircn);

	return 0;
}

/* �ж�ʱ���ʴ� */
int isIrc(const char *msg) {
	int boolean = 0;
	if (msg[0] == '[' && msg[1] == '0')
		boolean = 1;
	return boolean;
}

/* �ж�ʱ���ǩ���� */
int label(char *msg) {
	int count = 0;
	char *p_msg = msg;

	while (*p_msg != '\0') {
		if (*p_msg == '[')
			count++;
		p_msg++;
	}
	return count;
}

/* ���µ�ʱ���ʴ�����ѡ������ */
void sort(char *msg[], int n)
{
	int i, j, min;
	char *tmp;

	for (i = 0;i < n - 1;i++) {
		min = i;
		for (j = i + 1;j < n;j++)
			if (strcmp(msg[min], msg[j]) > 0)
				min = j;
				
		if (min != i) {
			tmp = msg[min];
			msg[min] = msg[i];
			msg[i] = tmp;
		}
	}
}

/* ��������ĸ�ʴ� */
void show(char *msg[], int n)
{
	int i, j;

	for (i = j = 0;i < n;i++) {
		puts(msg[i] + 10);
	}
}
