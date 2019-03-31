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
void reverse(struct Node *head){
	if(head == NULL)
		return;
	else {
		reverse(head->next);
		printf("%d\t", head->data);
	}	
}
void traverse(struct Node *head){
	if(head == NULL)
		printf("EMPTY LIST!");
	while(head != NULL){
		printf("%d\t", head->data);
		head = head->next;
	}
	printf("\n");
}
int main(){
	struct Node *head = NULL;
	insert_beg(&head, 1);
	insert_beg(&head, 2);
	insert_beg(&head, 3);
	insert_beg(&head, 4);
	insert_beg(&head, 5);
	traverse(head);
	reverse(head);
	printf("\n");
	return 0;
}
