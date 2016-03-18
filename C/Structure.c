# include <stdio.h>
# include <stdlib.h>

struct Data{
	int tmp;
	int val;
	struct Data *next;
};

int main (void){
	struct Data *news;
	struct Data *head;
	head = NULL;
	
	// 在链表开头添加元素 
	news = (Data *)malloc(sizeof(struct Data));
	news->next = head;
	head = news;
	
	// 在链表末尾添加元素
	struct Data *current;
	current = head;
	while(current->next != NULL)
		current = current->next;
	news = (Data *)malloc(sizeof(struct Data));
	current->next = news;
	news->next = NULL;
	
	// 在链表中间添加元素
	 
}
