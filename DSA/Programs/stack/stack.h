struct Stack{
	int top;
	int n;
	int* arr;
	struct Stack* stack;

};
void push(struct Stack*, int);
int pop(struct Stack*);
