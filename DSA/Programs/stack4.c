#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Stack{
	struct Node *head;
};
struct Node * newNode(int new_data){	
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = NULL;
	return new_node;
}
struct Stack * createStack(){	
	struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
	stack->head = NULL;
	return stack;
}
void push(struct Stack *stack, int new_data){
	struct Node *new_node = newNode(new_data);
	new_node->next = stack->head;
	stack->head = new_node;
}
void pop(struct Stack *stack){
	if(stack->head == NULL){
		printf("NOTHING TO DELETE!\n");
		return;
	}
	struct Node *temp = stack->head;
	stack->head = stack->head->next;
	free(temp);
}
void traverse(struct Stack *stack){
	if(stack->head == NULL)
		printf("EMPTY STACK!");
	struct Node *node = stack->head;
	while(node != NULL){
		printf("%d\n", node->data);
		node = node->next;
	}
}
int main(){
	struct Stack *stack = createStack();
	push(stack, 1);
	push(stack, 2);
	traverse(stack);	
	printf("\n");
	push(stack, 3);
	push(stack, 4);
	push(stack, 5);
	traverse(stack);	
	printf("\n");
	pop(stack);
	traverse(stack);
	printf("\n");
	pop(stack);
	traverse(stack);
	return 0;
}
