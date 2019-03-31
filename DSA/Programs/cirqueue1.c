#include<stdio.h>
# define SIZE 5
void encirqueue(int CirQueue[], int *front, int *rear, int new_data){
	if((front == 0 && *rear == SIZE - 1) || (front == rear + 1))
		printf("CIRCULAR QUEUE IS FULL!\n");
	else if(*rear == -1){
		*front = 0;
		*rear = 0;
		CirQueue[*rear] = new_data;
	} else if(*rear == SIZE - 1){ 
		*rear = 0;
		CirQueue[*rear] = new_data; 
	} else
		CirQueue[++*rear] = new_data;
}
void decirqueue(int *front, int *rear){
	if(*front == -1)	
		printf("NOTHING TO DELETE!\n");
	else if(*front == *rear){
		*front = -1;
		*rear = -1;
	} else if(*front == SIZE - 1)
		*front = 0;
	else		
		++*front;
}
void traverse(int CirQueue[], int front, int rear){
	if(front == -1)
		printf("EMPTY CIRCULAR QUEUE!");
	if(rear >= front){
/*		for(int i = 0; i < front; i++)
			printf("-\t");
		printf("-->\t");
*/		while(front <= rear)
			printf("%d\t", CirQueue[front++]);
//		printf("<--\t");
	} else {
/*		for(int i = 0; i < rear; i++)
			printf("%d\t", CirQueue[i++]);
		printf("<--\t");
		for(int i = rear; i < front; i++)
			printf("-\t");
		printf("-->\t");
*/		while(front <= SIZE - 1)
			printf("%d\t", CirQueue[front++]);
		for(int i = 0; i < rear; i++)
			printf("%d\t", CirQueue[i++]);
	}	
	printf("\n");
}
int main(){
	int CirQueue[SIZE], front = -1, rear = -1;
	encirqueue(CirQueue, &front, &rear, 1);
	encirqueue(CirQueue, &front, &rear, 2);	
	traverse(CirQueue, front, rear);
	encirqueue(CirQueue, &front, &rear, 3);	
	encirqueue(CirQueue, &front, &rear, 4);	
	encirqueue(CirQueue, &front, &rear, 5);	
	traverse(CirQueue, front, rear);
	decirqueue(&front, &rear);
	traverse(CirQueue, front, rear);
	decirqueue(&front, &rear);
	traverse(CirQueue, front, rear);
	encirqueue(CirQueue, &front, &rear, 6);	
	encirqueue(CirQueue, &front, &rear, 7);	
	traverse(CirQueue, front, rear);		
	return 0;
}
