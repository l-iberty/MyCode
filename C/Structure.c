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
	
	// ������ͷ���Ԫ�� 
	news = (Data *)malloc(sizeof(struct Data));
	news->next = head;
	head = news;
	
	// ������ĩβ���Ԫ��
	struct Data *current;
	current = head;
	while(current->next != NULL)
		current = current->next;
	news = (Data *)malloc(sizeof(struct Data));
	current->next = news;
	news->next = NULL;
	
	// �������м����Ԫ��
	 
}
