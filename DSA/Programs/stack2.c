#include<stdio.h>
# define SIZE 100
void push(int Stack[], int *head, int new_data){
	if(*head == SIZE - 1){
		printf("STACK IS FULL!\n");
		return;
	}
	Stack[++*head] = new_data;
}
void pop(int *head){
	if(*head == -1){
		printf("NOTHING TO DELETE!\n");
		return;
	}
	--*head;
}
void traverse(int Stack[], int head){
	if(head == -1)
		printf("EMPTY STACK!");
	while(head != -1)
		printf("%d\n", Stack[head--]);
}
int main(){
	int Stack[SIZE], head = -1;
	push(Stack, &head, 1);
	push(Stack, &head, 2);
	traverse(Stack, head);
	printf("\n");
	push(Stack, &head, 3);
	push(Stack, &head, 4);
	push(Stack, &head, 5);
	traverse(Stack, head);	
	printf("\n");
	pop(&head);
	traverse(Stack, head);
	printf("\n");
	pop(&head);
	traverse(Stack, head);	
	return 0;
}
