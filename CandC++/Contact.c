#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct People* addRecord(struct People *head, struct People *new, char *inName, char *inTel);
int searchRecord(struct People *head);
void show(struct People *head, int index);
struct People* deleteRecord(struct People *head);
struct People* delFisrt(struct People *head);
struct People* delMiddle(struct People *head, int index);
struct People* delLast(struct People *head);
void display(struct People *head);
int size(struct People *head);
int equals(const char *str1, const char *str2);
char* strcpy(char *dest, const char *source);
void trash(struct People *head);

struct People {
	char name[10];
	char telephone[12];
	struct People *next;
};

int main() {
	int flag, flag1, flag2, index;
	struct People *head, *new;
	head = NULL;
	char choice;
	char inName[10], inTel[12];

	flag = 1;
	while (flag) {
		printf("\n\n------------Contact------------");
		printf("\n1.Add record\n");
		printf("2.Delete record\n");
		printf("3.Search record\n");
		printf("4.Display records\n");
		printf("5.Exit\n");
		printf("Please enter the matching number to choose the operation.\n");
		choice = getch();
		
		switch (choice) {
		case '1':
			flag1 = 1;
			do{
				printf("\nPlease enter the name: ");
				scanf("%s", inName);
				printf("Please enter the telephone: ");
				scanf("%s", inTel);
				new = (struct People*)malloc(sizeof(struct People));
				head = addRecord(head, new, inName, inTel);
				
				flag2 = 1;
				while(flag2){
					printf("\nContinue to add record? Y\\N ");
					choice = getch();
					if(choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n')
						flag2 = 0;
					else
						printf("Invailid Input!\n");
				}
				if(choice == 'N' || choice == 'n')
					flag1 = 0;
			} while (flag1);
			
			break;
		case '2':
			head = deleteRecord(head);
			break;
		case '3':
			index = searchRecord(head);
			show(head, index);
			break;
		case '4':
			display(head);
			printf("Press any key to continue...");
			getch();
			break;
		case '5':
			flag = 0;
			break;
		default:
			printf("\nInvalid Input!\n");
		}
	}
	
	trash(head);
	return 0;
}

struct People* addRecord(struct People *head, struct People *new, char *inName, char *inTel)
{
	struct People *current;
	strcpy(new->name, inName);
	strcpy(new->telephone, inTel);
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

int searchRecord(struct People *head) {
	int index = 0, flag = 1;
	char name[10], telephone[12], type;
	struct People* current;
	current = head;

	if(!size(head)){
		printf("\nNo records!\n");
		return 0;
	}
	
	printf("1.Search by name\n");
	printf("2.Search by telephone\n");
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
		printf("\nPlease enter the telephone: ");
		scanf("%s", telephone);
		while (current != NULL) {
			index++;
			if (equals(telephone, current->telephone))
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

void show(struct People *head, int index){
	struct People *current;
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
	printf("Telephone: %s\n", current->telephone);
	printf("Press any key to continue...");
	getch();
}

void display(struct People *head) {
	struct People *current;
	int i = 1;
	current = head;
	
	if(!size(head)){
		printf("\nNo records!\n");
		return;
	}
	
	while (current != NULL) {
		printf("\nRecord %d:", i++);
		printf("\nName: %s\n", current->name);
		printf("Telephone: %s\n", current->telephone);
		current = current->next;
	}
}

struct People* deleteRecord(struct People *head)
{
	char index;
	int d;
	
	if(!size(head)){
		printf("\nNo records!\n");
		return;
	}
	
	display(head);
	printf("Please enter the matching number to delete. ");
	index = getch();
	d = index - '0';
	
	if (d == 1)
		head = delFisrt(head);
	else if (d == size(head))
		head = delLast(head);
	else if(d > 1 && d < size(head))
		head = delMiddle(head, d);
	else
		printf("\nInvalid Input\n");
		
	return head;
}

struct People* delFisrt(struct People *head)
{
	struct People *tmp;
	tmp = head;
	head = head->next;
	free(tmp);
	return head;
}

struct People* delLast(struct People *head)
{
	struct People *tmp1, *tmp2;/* tmp1标记倒数第二个最后一个,tmp2标记最后一个 */
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

struct People* delMiddle(struct People *head, int index)
{
	int i = 2;
	struct People *tmp1, *tmp2;
	/* tmp1标记待删除元素的前一个,tmp2标记待删除元素 */
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

int size(struct People *head)
{
	struct People *current;
	int count = 0;

	current = head;
	while (current != NULL) {
		current = current->next;
		count++;
	}
	return count;
}

int equals(const char *str1, const char *str2)
{
	/* 实现类似Java中String类的equals()方法的功能 */
	char *ch1, *ch2;
	ch1 = (char *)str1;
	ch2 = (char *)str2;

	while (*ch1 == *ch2 && *ch1 && *ch2) {
		ch1++;
		ch2++;
	}
	if (!(*ch1) && !(*ch2)) // 同时到达行尾字符
		return 1;
	else
		return 0;
}

char* strcpy(char *dest, const char *source)
{
	char *ch = dest;
	while((*(dest++) = *(source++)) != '\0');
	return ch;
}

void trash(struct People *head)
{
	struct People *current, *tmp;
	current = head;
	
	while(current != NULL){
		tmp = current;
		current = current -> next;
		free(tmp);
	}
}
