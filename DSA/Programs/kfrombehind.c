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
void kfrombehind(struct Node *head, int k){
	if(head == NULL)
		printf("EMPTY LIST!");
	struct Node *ptr1 = head, *ptr2 = head;
	int count = 0;
	while(ptr1 != NULL){
		if (count == k){
			printf("%d\t", ptr2->data);
			ptr2 = ptr2->next;
		} else 
			count += 1;
		ptr1 = ptr1->next;
	}
	if(count < k || k < 0)		
		printf("NOT POSSIBLE!");
	else if(ptr2 == head)
		printf("EMPTY LIST!");		
	printf("\n");
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
	kfrombehind(head, 1);	
	return 0;
}
