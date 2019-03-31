#include<stdio.h>
#include<stdlib.h>
struct Max_node{
	int data;
	struct Max_node *next;
};
void Max_push(struct Max_node **head_ref, int new_data){
	struct Max_node *new_node = (struct Max_node *)malloc(sizeof(struct Max_node));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}
struct Node{
	int data;
	struct Node *next;
};
void push(struct Node **head_ref, struct Max_node **Max_head_ref, int new_data){
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
	struct Node *top = *head_ref;
	if(Max_head_ref == NULL)
		Max_push(Max_head_ref, top->data);
	if(top->next != NULL)
		if(top->data > top->next->data)
			Max_push(Max_head_ref, top->data);
		else
			Max_push(Max_head_ref, top->next->data); 
}
void pop(struct Node **head_ref, struct Max_node **Max_head_ref){
	if(*head_ref == NULL){
		printf("NOTHING TO DELETE!\n");
		return;
	}
	struct Node *temp = *head_ref;
	*head_ref = temp->next;
	free(temp);
	struct Max_node *Max_temp = *Max_head_ref;
	*Max_head_ref = Max_temp->next;
	free(Max_temp);
}
void traverse(struct Node *head){
	if(head == NULL)
		printf("EMPTY LIST!");
	while(head != NULL){
		printf("%d\n", head->data);
		head = head->next;
	}
}
int main(){
	struct Node *head = NULL;
	struct Max_node *Max_head = NULL;
	push(&head, &Max_head, 3);
	push(&head, &Max_head, 4);
	push(&head, &Max_head, 2);
	traverse(head);	
	printf("Maximum element in current stack is %d...\n", Max_head->data); 
	printf("\n");
	push(&head, &Max_head, 4);
	push(&head, &Max_head, 5);
	traverse(head);	
	printf("Maximum element in current stack is %d...\n", Max_head->data); 
	printf("\n");	
	pop(&head, &Max_head);
	pop(&head, &Max_head);
	pop(&head, &Max_head);
	pop(&head, &Max_head);
	push(&head, &Max_head, 6);
	push(&head, &Max_head, 4);
	traverse(head);	
	printf("Maximum element in current stack is %d...\n", Max_head->data); 
	return 0;
}
