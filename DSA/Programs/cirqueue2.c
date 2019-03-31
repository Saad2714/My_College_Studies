#include<stdio.h>
#include<stdlib.h>
struct CirQueue{
	int head, tail, size;
	unsigned capacity;
	int *array;	
};
struct CirQueue * createCirQueue(unsigned capacity){
	struct CirQueue *cirqueue = (struct CirQueue *)malloc(sizeof(struct CirQueue));
	cirqueue->capacity = capacity;
	cirqueue->head = 0;
	cirqueue->size = 0;
	cirqueue->tail = capacity - 1;	
	cirqueue->array = (int *)malloc(cirqueue->capacity * sizeof(int));
	return cirqueue;
}
int isFull(struct CirQueue *cirqueue){
	return cirqueue->size == cirqueue->capacity;
}
int isEmpty(struct CirQueue *cirqueue){
	return cirqueue->size == 0;
}
void encirqueue(struct CirQueue *cirqueue, int new_data){
	if(isFull(cirqueue)){
		printf("QUEUE IS FULL!\n");
		return;
	}
	cirqueue->tail = (cirqueue->tail + 1) % cirqueue->capacity;
	cirqueue->array[cirqueue->tail] = new_data;
	++cirqueue->size;
}
void decirqueue(struct CirQueue *cirqueue){
	if(isEmpty(cirqueue)){	
		printf("NOTHING TO DELETE!\n");
		return;
	}	
	cirqueue->head = (cirqueue->head + 1) % cirqueue->capacity;
	--cirqueue->size;
}
void traverse(struct CirQueue *cirqueue){
	if(isEmpty(cirqueue)){	
		printf("EMPTY QUEUE!\n");
		return;
	}	
	int front = (cirqueue->head) % cirqueue->capacity, rear = (cirqueue->tail) % cirqueue->capacity;
	if(rear >= front){
		for(int i = 0; i < front; i++)
			printf("-\t");
		printf("-->\t");
		while(front <= rear)
			printf("%d\t", cirqueue->array[front++]);
		printf("<--\t");
	} else {
		for(int i = 0; i < rear; i++)
			printf("%d\t", cirqueue->array[i++]);
		printf("<--\t");		
		for(int i = rear; i < front; i++)
			printf("-\t");
		printf("-->\t");
		while(front <= cirqueue->size - 1)
			printf("%d\t", cirqueue->array[front++]);
	}	
	printf("\n");

}
int main(){
	struct CirQueue *cirqueue = createCirQueue(5);
	encirqueue(cirqueue, 1);
	encirqueue(cirqueue, 2);	
	traverse(cirqueue);
	encirqueue(cirqueue, 3);	
	encirqueue(cirqueue, 4);	
	encirqueue(cirqueue, 5);	
	traverse(cirqueue);
	decirqueue(cirqueue);
	traverse(cirqueue);
	decirqueue(cirqueue);
	traverse(cirqueue);
	encirqueue(cirqueue, 6);	
	encirqueue(cirqueue, 7);	
	traverse(cirqueue);	
	return 0;
}
