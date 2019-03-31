#include<stdio.h>
# define SIZE 5
void enqueue(int Queue[], int *head, int *tail, int new_data){
	if(*tail == SIZE - 1)
		printf("QUEUE IS FULL!\n");
	else if(*tail == -1){
		*head = 0;
		*tail = 0;
		Queue[*tail] = new_data;
	} else
		Queue[++*tail] = new_data;
}
void dequeue(int *head, int *tail){
	if(*head == -1)	
		printf("NOTHING TO DELETE!\n");
	else if(*head == *tail){
		*head = -1;
		*tail = -1;
	} else		
		++*head;
}
void traverse(int Queue[], int head, int tail){
	if(head == -1)
		printf("EMPTY QUEUE!");
	while(head <= tail)
		printf("%d\t", Queue[head++]);
	printf("\n");
}
int main(){
	int Queue[SIZE], head = -1, tail = -1;
	enqueue(Queue, &head, &tail, 1);
	enqueue(Queue, &head, &tail, 2);	
	traverse(Queue, head, tail);
	enqueue(Queue, &head, &tail, 3);	
	enqueue(Queue, &head, &tail, 4);	
	enqueue(Queue, &head, &tail, 5);	
	traverse(Queue, head, tail);
	dequeue(&head, &tail);
	traverse(Queue, head, tail);
	dequeue(&head, &tail);
	traverse(Queue, head, tail);
	enqueue(Queue, &head, &tail, 6);	
	traverse(Queue, head, tail);	
	return 0;
}
