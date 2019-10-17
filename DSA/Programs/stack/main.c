#include"stack.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
	struct Stack *stack=(struct Stack*)malloc(sizeof(struct Stack));
	stack->top=-1;
	stack->n=5;
	stack->arr=(int *)malloc(5*sizeof(int));
	push(stack,4);
	push(stack,2);
	printf("%d\n",pop(stack));
}
