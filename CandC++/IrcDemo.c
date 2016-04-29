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
	/* strn为总行数, ircn为有效歌词行数, time_label为时间标签个数*/
	char str[100][100], time_irc_str[100][100], time_str[100][100], irc_str[100][100],
		new_time_irc_str[100][100], *p[100];
	if ((fp = fopen("C:\\Users\\len\\Desktop\\小幸运.Irc", "r")) == NULL) {
		fprintf(stderr, "error\n");
		exit(1);
	}

	i = 0;
	while ((ch = fgetc(fp)) != EOF) {
		j = 0;
		while (ch != '\n') {
			// i标记行, j标记每行的每个字符
			str[i][j++] = ch;
			ch = fgetc(fp);
		}
		str[i++][j] = '\0';
		/* 退出内层while时, ch为'\n', 在下一轮进入外层while后立即被更新为下一行的第一个字符 */
	}
	strn = i;
	fclose(fp);
	/* for (j = 0;j < i;j++) puts(str[j]); 输出歌词串 */

	/* 取出时间歌词串 */
	for (i = j = 0;i < strn;i++) {
		if (isIrc(str[i])) {
			strcpy(time_irc_str[j++], str[i]);
			// puts(time_irc_str[j - 1]);
		}
	}
	ircn = j;

	/* 取出时间歌词串中的时间标签和歌词 */
	for (i = k = s = 0;i < ircn;i++) {
		// i是时间歌词的行标记
		// k是时间标签的行标记
		time_label = label(time_irc_str[i]);
		for (j = r = 0;r < time_label;r++, j += 10) {
			/* j+=10, 将读取起点置于该行的下一个时间标签 */
			for (t = 0;t < 10;t++) time_str[k][t] = time_irc_str[i][t + j];
			time_str[k++][t] = '\0';
			//puts(time_str[k-1]);
		}
		// 第一层for遍历时间歌词串
		// 第二层for遍历每个时间歌词串的所有时间标签
		// 第三层for将每个时间标签读入time_str[][]

		t = 10 * time_label;
		// 每个时间标签有10个字符, 由此跳过时间标签读取后面的歌词
		// 注意歌词行数等于时间歌词行数
		for (j = t, r = 0;time_irc_str[i][j] != '\0';j++, r++) {
			irc_str[i][r] = time_irc_str[i][j];
		}
		irc_str[i][r] = '\0';
		//puts(irc_str[i]);

		/* 将时间标签和歌词拼接成新的时间歌词串 */
		for (j = 0;j < time_label;j++, s++) {
			strcpy(new_time_irc_str[s], time_str[s]);
			strcat(new_time_irc_str[s], irc_str[i]);
			/* 对于每次确定的i行, 需要将其拼接到多少个时间标签后面由该行
               的时间标签数决定. 在这个for中, 循环次数控制了每行歌词的重
			   复次数: s标记新的时间歌词串的行, 每个确定的i行有几个时间
			   标签就迭代几次 */
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

/* 判定时间歌词串 */
int isIrc(const char *msg) {
	int boolean = 0;
	if (msg[0] == '[' && msg[1] == '0')
		boolean = 1;
	return boolean;
}

/* 判定时间标签个数 */
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

/* 对新的时间歌词串进行选择排序 */
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

/* 输出排序后的歌词串 */
void show(char *msg[], int n)
{
	int i, j;

	for (i = j = 0;i < n;i++) {
		puts(msg[i] + 10);
	}
}
