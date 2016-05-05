#include <stdio.h>
#include <stdlib.h>

struct Book {
	char name[20], ID[20], author[20], edYear[20];
	struct Book *next;
};

void readFile(char TmpName[][20], char TmpID[][20], char TmpAuthor[][20], char TmpEdYear[][20]);
void writeFile(struct Book *head);
struct Book* addBook(struct Book *head, struct Book *new, char *inName, char *inID, char *inAuthor, char *inEdYear);
struct Book* deleteBook(struct Book *head);
struct Book* delFisrt(struct Book *head);
struct Book* delLast(struct Book *head);
struct Book* delMiddle(struct Book *head, int index);
int queryBook(struct Book *head);
void show(struct Book *head, int index);
void displayBook(struct Book *head);
int size(struct Book *head);
char* strcpy(char *dest, const char *source);
int equals(const char *str1, const char *str2);

int main()
{
	char TmpName[3][20], TmpID[3][20], TmpAuthor[3][20], TmpEdYear[3][20];
	char inName[20], inID[20], inAuthor[20], inEdYear[20];
	int flag, flag1, flag2, i, index;
	char choice;
	struct Book *head, *new;
	head = NULL;

	readFile(TmpName, TmpID, TmpAuthor, TmpEdYear);

	for(i = 0;i < 3;i++) {
		strcpy(inName, TmpName[i]);
		strcpy(inID, TmpID[i]);
		strcpy(inAuthor, TmpAuthor[i]);
		strcpy(inEdYear, TmpEdYear[i]);
		new = (struct Book*)malloc(sizeof(struct Book));
		head = addBook(head, new, inName, inID, inAuthor, inEdYear);
	}

	flag = 1;
	while (flag) {
		printf("\n\n------------Book Management System------------\n");
		printf("1.Add Books\n");
		printf("2.Delete Books\n");
		printf("3.Query Books\n");
		printf("4.Display Books\n");
		printf("5.Exit\n");
		printf("Please enter the matching number to choose the operation.\n");
		choice = getch();

		switch (choice) {
		case '1':
			flag1 = 1;
			do {
				printf("\nPlease enter the name: ");
				scanf("%s", inName);
				printf("Please enter the ID: ");
				scanf("%s", inID);
				printf("Please enter the author: ");
				scanf("%s", inAuthor);
				printf("Please enter the edition-year: ");
				scanf("%s", inEdYear);
				new = (struct Book*)malloc(sizeof(struct Book));
				head = addBook(head, new, inName, inID, inAuthor, inEdYear);

				flag2 = 1;
				while (flag2) {
					printf("\nContinue to add record? Y\\N ");
					choice = getch();
					if (choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n')
						flag2 = 0;
					else
						printf("Invailid Input!\n");
				}
				if (choice == 'N' || choice == 'n')
					flag1 = 0;
			} while (flag1);

			break;
		case '2':
			head = deleteBook(head);
			break;
		case '3':
			index = queryBook(head);
			show(head, index);
			break;
		case '4':
			displayBook(head);
			printf("Press any key to continue...");
			getch();
			break;
		case '5':
			writeFile(head);
			flag = 0;
			break;
		default:
			printf("\nInvalid Input!\n");
		}
	}

	return 0;
}

void readFile(char TmpName[][20], char TmpID[][20], char TmpAuthor[][20], char TmpEdYear[][20])
{
	FILE *fp;
	char str[15][30];
	int ch, i, j, k, offset, strn;
	int namel, IDl, authorl, edYearl;

	if((fp = fopen("books.txt", "r")) == NULL){
		printf("error!\n");
		exit(1);
	}

	i = 0;
	while((ch = fgetc(fp)) != EOF) {
		j = 0;
		while(ch != '\n' && ch != EOF) {
			str[i][j++] = ch;
			ch = fgetc(fp);
		}
		str[i++][j] = '\0';
	}
	fclose(fp);
	strn = i;

	namel = IDl = authorl = edYearl = 0;
	for(i = 0; i < strn; i++) {
		if(str[i][0] == 'N') {
			offset = 6;
			j = 0;
			while(str[i][offset]) {
				TmpName[namel][j++] = str[i][offset++];
			}
			TmpName[namel][j] = '\0';
			namel++;
		}
		if(str[i][0] == 'I') {
			offset = 4;
			j = 0;
			while(str[i][offset]) {
				TmpID[IDl][j++] = str[i][offset++];
			}
			TmpID[IDl][j] = '\0';
			IDl++;
		}
		if(str[i][0] == 'A') {
			offset = 8;
			j = 0;
			while(str[i][offset]) {
				TmpAuthor[authorl][j++] = str[i][offset++];
			}
			TmpAuthor[authorl][j] = '\0';
			authorl++;
		}
		if(str[i][0] == 'E') {
			offset = 13;
			j = 0;
			while(str[i][offset]) {
				TmpEdYear[edYearl][j++] = str[i][offset++];
			}
			TmpEdYear[edYearl][j] = '\0';
			edYearl++;
		}
	}
}

void writeFile(struct Book *head)
{
	FILE *fp;
	struct Book *current;
	if((fp = fopen("books_s.txt", "w")) == NULL){
		printf("error!\n");
		exit(1);
	}

	current = head;
	while(current != NULL){
		fprintf(fp, "Name: ");
		fprintf(fp, current->name);
		fprintf(fp, "\n");
		fprintf(fp, "ID: ");
		fprintf(fp, current->ID);
		fprintf(fp, "\n");
		fprintf(fp, "Author: ");
		fprintf(fp, current->author);
		fprintf(fp, "\n");
		fprintf(fp, "EditionYear: ");
		fprintf(fp, current->edYear);
		fprintf(fp, "\n\n");
		current = current->next;
	}
	fclose(fp);
}

struct Book* addBook(struct Book *head, struct Book *new, char *inName, char *inID, char *inAuthor, char *inEdYear)
{
	struct Book *current;
	strcpy(new->name, inName);
	strcpy(new->ID, inID);
	strcpy(new->author, inAuthor);
	strcpy(new->edYear, inEdYear);
	new->next = NULL;

	if (head == NULL) {
		head = new;
		return head;
	}

	current = head;
	while (current->next != NULL)
		current = current->next;

	current->next = new;
	return head;
}

struct Book* deleteBook(struct Book *head)
{
	char index;
	int d;

	if(!size(head)){
		printf("\nNo records!\n");
		return;
	}

	displayBook(head);
	printf("Please enter the matching order to delete. ");
	index = getch();
	d = index - '0';

	if (d == 1)
		head = delFisrt(head);
	else if (d == size(head))
		head = delLast(head);
	else if(d > 1 && d < size(head))
		head = delMiddle(head, d);
	else
		printf("\nInvalid Input!\n");

	return head;
}

struct Book* delFisrt(struct Book *head)
{
	struct Book *tmp;
	tmp = head;
	head = head->next;
	free(tmp);
	return head;
}

struct Book* delLast(struct Book *head)
{
	struct Book *tmp1, *tmp2;
	tmp1 = head;
	tmp2 = tmp1->next;
	while (tmp2->next != NULL) {
		tmp1 = tmp2;
		tmp2 = tmp1->next;
	}
	tmp1->next = NULL;
	free(tmp2);

	return head;
}

struct Book* delMiddle(struct Book *head, int index)
{
	int i = 2;
	struct Book *tmp1, *tmp2;
	tmp1 = head;
	tmp2 = tmp1->next;

	while (i < index) {
		tmp1 = tmp2;
		tmp2 = tmp1->next;
		i++;
	}
	tmp1->next = tmp2->next;
	free(tmp2);

	return head;
}

int queryBook(struct Book *head)
{
	int index = 0, flag = 1;
	char name[20], ID[20], author[20], edYear[20], type;
	struct Book* current;
	current = head;

	if(!size(head)){
		printf("\nNo records!\n");
		return 0;
	}

	printf("1.Query by name\n");
	printf("2.Query by ID\n");
	printf("3.Query by author\n");
	printf("4.Query by editionYear\n");
	type = getch();

	if (type == '1') {
		printf("\nPlease enter the name: ");
		scanf("%s", name);
		while (current != NULL) {
			index++;
			if (equals(name, current->name))
				return index;
			else
				current = current->next;
		}
	}
	else if (type == '2') {
		printf("\nPlease enter the ID: ");
		scanf("%s", ID);
		while (current != NULL) {
			index++;
			if (equals(ID, current->ID))
				return index;
			else
				current = current->next;
		}
	}
	else if (type == '3') {
		printf("\nPlease enter the author: ");
		scanf("%s", author);
		while (current != NULL) {
			index++;
			if (equals(author, current->author))
				return index;
			else
				current = current->next;
		}
	}
	else if (type == '4') {
		printf("\nPlease enter the editionYear: ");
		scanf("%s", edYear);
		while (current != NULL) {
			index++;
			if (equals(edYear, current->edYear))
				return index;
			else
				current = current->next;
		}
	}
	else
		printf("\nInvalid Input!\n");

	if (current == NULL)
		return -1;
}

void show(struct Book *head, int index)
{
	struct Book *current;
	int i;

	if(index < 0){
		printf("\nNot Found!\n");
		return;
	}
	else if(!index)
		return;

	current = head;
	for(i = 1; i < index; i++,current = current->next);

	printf("\nName: %s\n", current->name);
	printf("ID: %s\n", current->ID);
	printf("Author: %s\n", current->author);
	printf("EditionYear: %s\n", current->edYear);
	printf("Press any key to continue...");
	getch();
}

void displayBook(struct Book *head)
{
	struct Book *current;
	int i = 1, sum;
	current = head;
	sum = size(head);

	if (!sum) {
		printf("\nNo records!\n");
		return;
	}

	printf("\n %d books in total.", sum);
	while (current != NULL) {
		printf("\nBook %d:", i++);
		printf("\nName: %s\n", current->name);
		printf("ID: %s\n", current->ID);
		printf("Author: %s\n", current->author);
		printf("EditionYear: %s\n", current->edYear);
		current = current->next;
	}
}

int size(struct Book *head)
{
	struct Book *current;
	int count = 0;

	current = head;
	while (current != NULL) {
		current = current->next;
		count++;
	}
	return count;
}

char* strcpy(char *dest, const char *source)
{
	char *ch = dest;
	while ((*(dest++) = *(source++)) != '\0');
	return ch;
}

int equals(const char *str1, const char *str2)
{
	char *ch1, *ch2;
	ch1 = (char *)str1;
	ch2 = (char *)str2;

	while (*ch1 == *ch2 && *ch1 && *ch2) {
		ch1++;
		ch2++;
	}
	if (!(*ch1) && !(*ch2))
		return 1;
	else
		return 0;
}
