#include<stdio.h>
#include<stdlib.h>
struct Stack{
	int head;
	unsigned capacity;
	int *array;	
};
struct Stack * createStack(unsigned capacity){
	struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->head = -1;
	stack->array = (int *)malloc(stack->capacity * sizeof(int));
	return stack;
}
int isFull(struct Stack *stack){
	return stack->head == stack->capacity - 1;
}
int isEmpty(struct Stack *stack){
	return stack->head == - 1;
}
void push(struct Stack *stack, int new_data){
	if(isFull(stack)){
		printf("STACK IS FULL!\n");
		return;
	}
	stack->array[++stack->head] = new_data;
}
void pop(struct Stack * stack){
	if(isEmpty(stack)){
		printf("NOTHING TO DELETE!\n");
		return;
	}
	--stack->head;
}
void traverse(struct Stack * stack){
	if(isEmpty(stack))
		printf("EMPTY STACK!");
	int top = stack->head;
	while(top != -1)
		printf("%d\n", stack->array[top--]);
}
int main(){
	struct Stack *stack = createStack(100);
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
