#include<stdio.h>
#include<stdlib.h>
#include"stack_node.h"
struct Node* push(struct Node* top, int x)
{
	if(size>=n)
		printf("Full");
	else{
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=x;
	newNode->next=top;
	top=newNode;
	size++;
	}
	return top;
}
int pop(struct Node* top)
{
	if(size<=0||!top)
	{
		printf("Empty");
	}
	int data=top->data;
	top=top->next;
	size--;
	return data;
}

