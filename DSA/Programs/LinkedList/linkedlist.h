struct Node
{
	int data;
	struct Node* next;
};
void print(struct Node*);
struct Node* insertatbeg(struct Node*, int);
struct Node* insertatend(struct Node*, int);
//void deleteatpos(struct Node*, int);
