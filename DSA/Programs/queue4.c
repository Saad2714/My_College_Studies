#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Queue{
	struct Node *head, *tail;
};
struct Node * newNode(int new_data){	
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = NULL;
	return new_node;
}
struct Queue * createQueue(){	
	struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
	queue->head = NULL;
	queue->tail = NULL;
	return queue;
}
void enqueue(struct Queue *queue, int new_data){
	struct Node *new_node = newNode(new_data);
	if(queue->tail == NULL){
		queue->head = new_node;
		queue->tail = new_node;
		return;
	}
	queue->tail->next = new_node;
	queue->tail = new_node;
}
void dequeue(struct Queue *queue){
	if(queue->head == NULL){
		printf("NOTHING TO DELETE!\n");
		return;
	}
	struct Node *temp = queue->head;
	queue->head = queue->head->next;
	if(queue->head == NULL)
		queue->head;
	free(temp);
}
void traverse(struct Queue *queue){
	if(queue->head == NULL)
		printf("EMPTY QUEUE!");
	struct Node *front = queue->head;
	while(front != NULL){
		printf("%d\t", front->data);
		front = front->next;
	}
	printf("\n");
}
int main(){
	struct Queue *queue = createQueue();
	enqueue(queue, 1);
	enqueue(queue, 2);
	traverse(queue);	
	enqueue(queue, 3);
	enqueue(queue, 4);
	enqueue(queue, 5);
	traverse(queue);
	dequeue(queue);
	traverse(queue);
	dequeue(queue);
	traverse(queue);	
	return 0;
}
