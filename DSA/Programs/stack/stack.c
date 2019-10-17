#include"stack.h"
#include<stdio.h>
void push(struct Stack* stack, int x)
{
	if(stack->top==stack->n-1){
		printf("Full");
	}
	stack->arr[++stack->top]=x;
}
int pop(struct Stack* stack)
{
	if(stack->top==-1)
		printf("Empty");
	stack->top-=1;
	return stack->arr[stack->top];
}
