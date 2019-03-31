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
void insert_mid(struct Node *prev_node, int new_data){
	if(prev_node == NULL){
		printf("NOT POSSIBLE!\n");
		return;
	}
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}
void insert_end(struct Node **head_ref, int new_data){
	struct Node *tail = *head_ref;
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = NULL;
	if(tail == NULL){
		*head_ref = new_node;
		return;
	}	
	while(tail->next != NULL)
		tail = tail->next;
	tail->next = new_node;
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
	insert_mid(head, 2);
	insert_end(&head, 3);
	traverse(head);
	return 0;
}
