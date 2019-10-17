#include"linkedlist.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
	struct Node *head=(struct Node*)malloc(sizeof(struct Node));
	struct Node *root=head;
	for(int i=0;i<3;i++)
	{

		head->data=i;
		struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
		if(i==2)
			head->next=NULL;
		else
			head->next=temp;
		head=temp;
	}
	print(root);
	root=insertatbeg(root, 5);
	printf("New List:");
	print(root);
	root=insertatend(root, 15);
	printf("New List");
	print(root);
}
