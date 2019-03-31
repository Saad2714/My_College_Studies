#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
void enqueue(struct Node **head_ref, int new_data){
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
void dequeue(struct Node **head_ref){
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
		printf("EMPTY QUEUE!");
	while(head != NULL){
		printf("%d\t", head->data);
		head = head->next;
	}
	printf("\n");
}
int main(){
	struct Node *head = NULL;
	enqueue(&head, 1);
	enqueue(&head, 2);
	traverse(head);	
	enqueue(&head, 3);
	enqueue(&head, 4);
	enqueue(&head, 5);
	traverse(head);
	dequeue(&head);
	traverse(head);
	dequeue(&head);
	traverse(head);	
	return 0;
}
