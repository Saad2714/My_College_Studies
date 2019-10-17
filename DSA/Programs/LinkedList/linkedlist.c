#include<stdlib.h>
#include<stdio.h>
#include"linkedlist.h"
void print(struct Node *root)
{
	struct Node* k=root;
	while(k!=NULL){
	printf("%d \n",k->data);
	k=k->next;
	}
}
struct Node* insertatbeg(struct Node* root, int d)
{
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=d;
	temp->next=root;
	root=temp;
	return root;
}
struct Node* insertatend(struct Node* root, int d)
{
	struct Node *temp=root;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	struct Node *new=(struct Node*)malloc(sizeof(struct Node));
	temp->next=new;
	new->data=d;
	new->next=NULL;
	return root;
}

