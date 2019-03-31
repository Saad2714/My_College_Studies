#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
void push(struct Node **head_ref, int new_data){
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}
void pop(struct Node **head_ref){
	if(*head_ref == NULL){
		printf("NOTHING TO DELETE!\n");
		return;
	}
	struct Node *temp = *head_ref;
	*head_ref = temp->next;
	free(temp);
}
void traverse(struct Node *head){
	if(head == NULL)
		printf("EMPTY STACK!");
	while(head != NULL){
		printf("%d\n", head->data);
		head = head->next;
	}
}
int main(){
	struct Node *head = NULL;
	push(&head, 1);
	push(&head, 2);
	traverse(head);
	printf("\n");
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	traverse(head);	
	printf("\n");
	pop(&head);
	traverse(head);
	printf("\n");
	pop(&head);
	traverse(head);	
	return 0;
}
