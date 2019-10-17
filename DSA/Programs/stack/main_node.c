#include<stdio.h>
#include<stdlib.h>
#include"stack_node.h"
int main()
{
	int k;
	struct Node* top=(struct Node*)malloc(sizeof(struct Node));
	top=push(top, 10);
	top=push(top, 20);
	top=push(top, 30);
	k=pop(top);
	printf("%d",k);
}
