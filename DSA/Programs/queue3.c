#include<stdio.h>
#include<stdlib.h>
struct Queue{
	int head, tail, size;
	unsigned capacity;
	int *array;	
};
struct Queue * createQueue(unsigned capacity){
	struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->head = 0;
	queue->size = 0;
	queue->tail = capacity - 1;	
	queue->array = (int *)malloc(queue->capacity * sizeof(int));
	return queue;
}
int isFull(struct Queue *queue){
	return queue->size == queue->capacity;
}
int isEmpty(struct Queue *queue){
	return queue->size == 0;
}
void enqueue(struct Queue *queue, int new_data){
	if(isFull(queue)){
		printf("QUEUE IS FULL!\n");
		return;
	}
	queue->tail = (queue->tail + 1) % queue->capacity;
	queue->array[queue->tail] = new_data;
	++queue->size;
}
void dequeue(struct Queue *queue){
	if(isEmpty(queue)){	
		printf("NOTHING TO DELETE!\n");
		return;
	}	
	queue->head = (queue->head + 1) % queue->capacity;
	--queue->size;
}
void traverse(struct Queue *queue){
	if(isEmpty(queue)){	
		printf("EMPTY QUEUE!\n");
		return;
	}	
	int count = 0, front = queue->head;
	while(count < queue->size){
		printf("%d\t", queue->array[front++ % queue->capacity]);
		count++;
	}
	printf("\n");
}
int main(){
	struct Queue *queue = createQueue(5);
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
	enqueue(queue, 6);	
	enqueue(queue, 7);	
	traverse(queue);	
	return 0;
}
