#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
void insert_beg(struct Node **head_ref, int new_data){
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}
int cycle(struct Node *head){
	struct Node *ptr1 = head, *ptr2 = head;
	while(ptr1 != NULL && ptr2 != NULL){
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
		if(ptr1 == ptr2)
			return 1;	
	}
	return 0;
}
int main(){
	struct Node *head = NULL;	
	insert_beg(&head, 0);
	insert_beg(&head, 1);
	insert_beg(&head, 2);
	insert_beg(&head, 3);
	insert_beg(&head, 4);
	insert_beg(&head, 5);
	insert_beg(&head, 6);
	insert_beg(&head, 7);
	insert_beg(&head, 8);
	insert_beg(&head, 9);
	struct Node *tail = head;
	while(tail->next != NULL){
		tail = tail->next;
	}
	struct Node *ptr = head;
	int count = 4;
	while(count--)
		ptr = ptr->next;
	tail->next = ptr;
	if(cycle(head))
		printf("Cycle detected!\n");
	else 
		printf("Cycle not detected!\n");
	return 0;
}
