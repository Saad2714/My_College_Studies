#include<stdio.h>
#include<stdlib.h>
struct Max_node1{
	int data;
	struct Max_node1 *next;
};
void Max_push1(struct Max_node1 **head_ref, int new_data){
	struct Max_node1 *new_node = (struct Max_node1 *)malloc(sizeof(struct Max_node1));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}
struct Max_node2{
	int data;
	struct Max_node2 *next;
};
void Max_push2(struct Max_node2 **head_ref, int new_data){
	struct Max_node2 *new_node = (struct Max_node2 *)malloc(sizeof(struct Max_node2));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}
struct Node1{
	int data;
	struct Node1 *next;
};
void push1(struct Node1 **head_ref, struct Max_node1 **Max_head_ref, int new_data){
	struct Node1 *new_node = (struct Node1 *)malloc(sizeof(struct Node1));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
	struct Node1 *top = *head_ref;	
	if(Max_head_ref == NULL)
		Max_push1(Max_head_ref, top->data);
	if(top->next != NULL)
		if(top->data > top->next->data)
			Max_push1(Max_head_ref, top->data);
		else
			Max_push1(Max_head_ref, top->next->data); 
}
void pop1(struct Node1 **head_ref, struct Max_node1 **Max_head_ref){
	if(*head_ref == NULL){
		printf("NOTHING TO DELETE!\n");
		return;
	}
	struct Node1 *temp = *head_ref;
	*head_ref = temp->next;
	free(temp);
	struct Max_node1 *Max_temp = *Max_head_ref;
	*Max_head_ref = Max_temp->next;
	free(Max_temp);
}
struct Node2{
	int data;
	struct Node2 *next;
};
void push2(struct Node2 **head_ref, struct Max_node2 **Max_head_ref, int new_data){
	struct Node2 *new_node = (struct Node2 *)malloc(sizeof(struct Node2));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
	struct Node2 *top = *head_ref;
	if(Max_head_ref == NULL)
		Max_push2(Max_head_ref, top->data);
	if(top->next != NULL)
		if(top->data > top->next->data)
			Max_push2(Max_head_ref, top->data);
		else
			Max_push2(Max_head_ref, top->next->data); 
}
void pop2(struct Node2 **head_ref, struct Max_node2 **Max_head_ref){
	if(*head_ref == NULL){
		printf("NOTHING TO DELETE!\n");
		return;
	}
	struct Node2 *temp = *head_ref;
	*head_ref = temp->next;
	free(temp);
	struct Max_node2 *Max_temp = *Max_head_ref;
	*Max_head_ref = Max_temp->next;
	free(Max_temp);
}
void enqueue(struct Node1 **head_ref, struct Max_node1 **Max_head_ref, int new_data){
	push1(head_ref, Max_head_ref, new_data);	
}
void dequeue(struct Node1 **head_ref1, struct Node2 **head_ref2, struct Max_node1 **Max_head_ref1, struct Max_node2 **Max_head_ref2){
	if(*head_ref1 == NULL && *head_ref2 == NULL){
		printf("NOTHING TO DELETE!\n");
		return;
	}
	if(*head_ref2 == NULL){
		struct Node1 *top = *head_ref1;
		while(top->next != NULL){
			push2(head_ref2, Max_head_ref2, top->data);
			pop1(head_ref1, Max_head_ref1);
			top = *head_ref1;
		}
	}
	pop2(head_ref2, Max_head_ref2);
}
void reverse(struct Node1 *head){
	if(head == NULL)
		return;
	else {
		reverse(head->next);
		printf("%d\t", head->data);
	}	
}
void traverse(struct Node1 *head1, struct Node2 *head2){
	if(head1 == NULL && head2 == NULL)
		printf("EMPTY LIST!");
	while(head2 != NULL){
		printf("%d\t", head2->data);
		head2 = head2->next;
	}
	reverse(head1);
	printf("\n");
}
int Maximum(struct Max_node1 *Max_head1, struct Max_node2 *Max_head2){
	if(Max_head1 == NULL)
		return Max_head2->data;
	else if(Max_head2 == NULL)
		return Max_head1->data;
	else{
		if(Max_head1->data > Max_head2->data)
			return Max_head1->data;
		else 
			return Max_head2->data;
	}		
}
int main(){
	struct Node1 *head1 = NULL;
	struct Node2 *head2 = NULL;
	struct Max_node1 *Max_head1 = NULL;
	struct Max_node2 *Max_head2 = NULL;
	enqueue(&head1, &Max_head1, 2);
	enqueue(&head1, &Max_head1, 3);
	enqueue(&head1, &Max_head1, 5);
	enqueue(&head1, &Max_head1, 1);
	traverse(head1, head2);
	printf("Maximum element in current queue is %d...\n", Maximum(Max_head1, Max_head2)); 
	printf("\n");		
	enqueue(&head1, &Max_head1, 6);
	enqueue(&head1, &Max_head1, 7);
	enqueue(&head1, &Max_head1, 4);	
	traverse(head1, head2);
	printf("Maximum element in current queue is %d...\n", Maximum(Max_head1, Max_head2)); 	
	printf("\n");
	dequeue(&head1, &head2, &Max_head1, &Max_head2);	
	dequeue(&head1, &head2, &Max_head1, &Max_head2);
	traverse(head1, head2);
	printf("Maximum element in current queue is %d...\n", Maximum(Max_head1, Max_head2)); 
	printf("\n");
	enqueue(&head1, &Max_head1, 5);
	enqueue(&head1, &Max_head1, 9);
	enqueue(&head1, &Max_head1, 8);
	traverse(head1, head2);
	printf("Maximum element in current queue is %d...\n", Maximum(Max_head1, Max_head2)); 
	return 0;
}
