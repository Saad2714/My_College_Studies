#include"stack.h"
#include<stdlib.h>
#include<stdio.h>
stack* createStack(int size)
{
	stack* temp = (stack*)malloc(sizeof(stack));
	temp->capacity= size;
	temp->top = -1;
	temp->data = (int*)malloc(temp->capacity*sizeof(int));
	return temp;
}

int isFull(stack* st)
{
	return st->top == st->capacity -1;
}

int isEmpty(stack* st)
{
	return st->top == -1;
}

void push(stack* st, int d)
{
	st->top++;
	st->data[st->top]= d;
}

int pop(stack* st)
{
	st->top--;
       return st->data[st->top+1];	
}

void printStack(stack* st)
{
	if(st->top>=0)
	{
		for(int i=0;i<=st->top;i++)
			printf("%d ", st->data[i]);
		printf("\n");
	}

	else
		printf("stack is empty\n");
}
