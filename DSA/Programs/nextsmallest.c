#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data, idx;
	struct Node *next;
};
void push(struct Node **head_ref, int new_data, int new_idx){
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->idx = new_idx;	
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
int main(){
	struct Node *head = NULL;
	int A[] = {2, 6, 7, 3, 9, 10, 8}, n = sizeof(A) / sizeof(A[0]), B[n];
	printf("Elements in the array are :\n");
	for(int i = 0; i < n; i++)
		printf("%d\t", A[i]);
	printf("\n");
	push(&head, A[0], 0);
	for(int i = 1; i < n; i++){
		int j = i;
		while(A[i] < head->data){
			B[--j] = i;
			pop(&head);
			if(head == NULL)
				break;
		}		
		push(&head, A[i], i);
	}
	while(head != NULL){
		B[head->idx] = 0;
		pop(&head);
	}
	printf("Indices of next smallest element for each of the elements in the array are :\n");
	for(int i = 0; i < n; i++)
		printf("%d\t", B[i]);
	printf("\n");
	return 0;
}
