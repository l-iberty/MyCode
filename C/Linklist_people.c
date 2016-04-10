# include <stdio.h>
# include <stdlib.h>
# include <conio.h>

struct people{
	char *name;
	char *ID;
	struct people *next;
};

int main(void){
	struct people *head = NULL;
	struct people *new_rec = NULL;
	struct people *current = NULL;
	struct people *tmp_rec = NULL;
	int i = 0;
	int N = 5;
	printf("Enter the number of the people: ");
	scanf("%d", &N);
	fflush(stdin); // 如果不清理stdin,最后按下的Enter会被33行的gets()获取,从而产生Bug. 
	
	if(N < 1){
		puts("Press any key to continue...");
		getch();
		return 1;
	}	
	
	new_rec = (struct people *)malloc(sizeof(struct people));
	head = new_rec;
	
	head->name = (char *)malloc(100 * sizeof(char));
	head->ID = (char *)malloc(10 * sizeof(char));
	printf("\nEnter the name: ");
	gets(head->name);
	printf("Enter the ID: ");
	gets(head->ID);
	
	head->next = NULL;
	
	tmp_rec = head;
	while(tmp_rec != NULL){
		if(++i >= N){
			tmp_rec = NULL;
			break;
		}
		
		new_rec = (struct people *)malloc(sizeof(struct people));
		
		if(new_rec == NULL){
			puts("error");
			exit(1);
		}
		
		tmp_rec->next = new_rec;
		tmp_rec = tmp_rec->next;
		
		tmp_rec->name = (char *)malloc(100 * sizeof(char));
		tmp_rec->ID = (char *)malloc(5 * sizeof(int));
		printf("\nEnter the name: ");
		gets(tmp_rec->name);
		printf("Enter the ID: ");
		gets(tmp_rec->ID);
		
		tmp_rec->next = NULL;
	}
	
	printf("\n");
	i = 0;
	current = head;
	while(current != NULL){
		printf("People %d: %s, %s\n", ++i, current->name, current->ID);
		current = current->next;
	}
	
	return 0;
}
