#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
void traverse(struct Node *head){
	if(head == NULL)
		printf("EMPTY LIST!");
	while(head != NULL){
		printf("%d\t", head->data);
		head = head->next;
	}
	printf("\n");
}
int main(){
	struct Node *head = (struct Node *)malloc(sizeof(struct Node));
	struct Node *mid = (struct Node *)malloc(sizeof(struct Node));
	struct Node *tail = (struct Node *)malloc(sizeof(struct Node));
	head->data = 1;
	head->next = mid;
	mid->data = 2;
	mid->next = tail;
	tail->data = 3;
	tail->next = NULL;
	traverse(head);
	return 0;
}
