#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
void insert_beg(struct Node **head_ref, int new_data){
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}
void delete_beg(struct Node **head_ref){
	if(*head_ref == NULL){
		printf("NOTHING TO DELETE!\n");
		return;
	}
	struct Node *temp = *head_ref;
	*head_ref = temp->next;
	free(temp);
}
void delete_node(struct Node **head_ref, int node_data){
	if(*head_ref == NULL){
		printf("NOTHING TO DELETE!\n");
		return;
	}
	struct Node *tail = *head_ref, *bef_tail;
	while(tail != NULL){
		if(tail->data == node_data){
			if(tail == *head_ref)
				*head_ref = tail->next;
			else if(tail->next == NULL)
				bef_tail->next = NULL;
			else 
				bef_tail->next = tail->next;
			free(tail);
			return;
		}
		bef_tail = tail;
		tail = tail->next;
	}
	printf("NODE NOT FOUND!\n");
}
void delete_pos(struct Node **head_ref, int node_pos){
	if(*head_ref == NULL){
		printf("NOTHING TO DELETE!\n");
		return;
	}
	struct Node *tail = *head_ref, *bef_tail;
	if(node_pos == 1){
		*head_ref = tail->next;
		free(tail);
		return;
	}
	bef_tail = tail;
	tail = tail->next;
	int count = 2;
	while(tail != NULL){
		if(count == node_pos){
			bef_tail->next = tail->next;
			free(tail);
			return;
		}
		bef_tail = tail;
		tail = tail->next;
	}		
	printf("POSITION NOT FOUND!\n");
}
void delete_end(struct Node **head_ref){
	if(*head_ref == NULL){
		printf("NOTHING TO DELETE!\n");
		return;
	}
	struct Node *tail = *head_ref, *bef_tail;
	if(tail->next == NULL){
		*head_ref = NULL;
		free(tail);
		return;
	}
	while(tail->next != NULL){
		bef_tail = tail;
		tail = tail->next;
	}
	bef_tail->next = NULL;
	free(tail);
}
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
	struct Node *head = NULL;
	insert_beg(&head, 1);
	insert_beg(&head, 2);
	insert_beg(&head, 3);
	insert_beg(&head, 4);
	insert_beg(&head, 5);
	traverse(head);
	delete_beg(&head);
	delete_end(&head);
	delete_node(&head, 3);
	delete_pos(&head, 2);
	traverse(head);
	return 0;
}
