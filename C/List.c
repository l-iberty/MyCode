# include <stdio.h>
# include <stdlib.h>

struct data{
	char *name;
	struct data *next;
};

int main(void){
	struct data *head = NULL;
	struct data *new_data = NULL;
	struct data *current = NULL;
	
	new_data = (struct data *)malloc(sizeof(struct data));
	new_data->next = head;
	head = new_data;
	head->name = "Abigail";
	
	current = head;
	while(current->next != NULL){
		current = current->next;
	}
	new_data = (struct data *)malloc(sizeof(struct data));
	current->next = new_data;
	new_data->next = NULL;
	new_data->name = "Jack";
	
	new_data = (struct data *)malloc(sizeof(struct data));
	new_data->next = head->next;
	head->next = new_data;
	new_data->name = "Godness";
	
	current = head;
	int i = 0;
	while(current != NULL){
		printf("list %d: %s\n", ++i, current->name);
		current = current->next;
	}
	
	return 0;
}
