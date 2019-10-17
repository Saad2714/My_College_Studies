#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct AdjListNode
{
	int dest;
	int weight;
	struct AdjListNode* next;
};
struct AdjList{
	struct AdjListNode* head;	//pointer to head node of list
};
struct Graph{
	int v;
	struct AdjList* array;
};
struct AdjListNode* newAdjListNode(int dest, int weight)
{
	struct AdjListNode* newNode=(struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	newNode->dest=dest;
	newNode->weight=weight;
	newNode->next=NULL;
	return newNode;
}
struct Graph* createGraph(int v)
{
	struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
	graph->v=v;
	graph->array=(struct AdjList*)malloc(v*sizeof(struct AdjList));
	for(int i=0;i<v;i++)
		graph->array[i].head=NULL;
	return graph;
}
void addEdge(struct Graph* graph, int src, int dest, int weight)
{
	struct AdjListNode* newNode = newAdjListNode(dest,weight);
	newNode->next=graph->array[src].head;
	graph->array[src].head=newNode;

	newNode=newAdjListNode(src, weight);
	newNode->next=graph->array[dest].head;
	graph->array[dest].head=newNode;
}
struct MinHeapNode
{
	int v;
	int key;
};
struct MinHeap{
	int size;
	int capacity;
	int* pos; //needed for decrease key
	struct MinHeapNode** array;
};
struct MinHeapNode* newMinHeapNode(int v, int key)
{
	struct MinHeapNode* minHeapNode=(struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
	minHeapNode->v=v;
	minHeapNode->key=key;
	return minHeapNode;
}
struct MinHeap* createMinHeap(int capacity)
{
	struct MinHeap* minHeap=(struct MinHeap*)malloc(sizeof(struct MinHeap));
	minHeap->pos=(int *)malloc(capacity*sizeof(int));
	minHeap->size=0;
	minHeap->capacity=0;
	minHeap->array=(struct MinHeapNode**)malloc(capacity*sizeof(struct MinHeapNode*));
	return minHeap;
}
//Swapping for minheapify
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
	struct MinHeapNode* t=*a;
	*a=*b;
	*b=t;
}
//function to heapify at i
void minHeapify(struct MinHeap* minHeap, int i)
{
	int p, lc, rc;
	p=i;
	lc=2*i+1;
	rc=2*i+2;
	if(lc<minHeap->size && minHeap->array[lc]->key<minHeap->array[p]->key)
		p=lc;
	if(rc<minHeap->size &&minHeap->array[rc]->key<minHeap->array[p]->key)
		p=rc;
	if(p!=i)
	{
		struct MinHeapNode* smallestNode = minHeap->array[p];
		struct MinHeapNode* iNode=minHeap->array[i];

		minHeap->pos[smallestNode->v]=i;
		minHeap->pos[iNode->v]=p;

		swapMinHeapNode(&minHeap->array[p], &minHeap->array[i]);
		minHeapify(minHeap, p);
	}
}
//utility fn to check for empty minheap
int isEmpty(struct MinHeap* minHeap)
{
	return minHeap->size==0;
}
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
	if(isEmpty(minHeap))
		return NULL;
	struct MinHeapNode* root=minHeap->array[0];

	struct MinHeapNode* lastNode=minHeap->array[minHeap->size-1];
	minHeap->array[0]=lastNode;
	minHeap->pos[root->v]=minHeap->size-1;
	minHeap->pos[lastNode->v]=0;
	--minHeap->size;
	minHeapify(minHeap,0);
	return root;
}
void decreaseKey(struct MinHeap* minHeap, int v, int key)
{
	int i=minHeap->pos[v];
	minHeap->array[i]->key=key;
	while(i && minHeap->array[i]->key<minHeap->array[(i-1)/2]->key)
	{
		minHeap->pos[minHeap->array[i]->v]=(i-1)/2;
		minHeap->pos[minHeap->array[(i-1)/2]->v]=i;
		swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i-1)/2]);
		i=(i-1)/2;
	}
}
int isinMinHeap(struct MinHeap* minHeap, int v)
{
	if(minHeap->pos[v]<minHeap->size)
		return 1;
	return 0;
}
void printArr(int arr[], int n)
{
	for(int i=1;i<n;i++)
		printf("%d - %d \n", arr[i], i);
}
void PrimMST(struct Graph* graph)
{
	int v=graph->v;
	int parent[v];
	int key[v];
	struct MinHeap* minHeap=createMinHeap(v);
	for(int i=1;i<v;i++)
	{
		parent[i]=-1;
		key[i]=INT_MAX;
		minHeap->array[i]=newMinHeapNode(i, key[i]);
		minHeap->pos[i]=i;
	}
	key[0]=0;
	minHeap->array[0]=newMinHeapNode(0, key[0]);
	minHeap->pos[0]=0;
	minHeap->size=v;

	while(!isEmpty(minHeap))
	{
		struct MinHeapNode* minHeapNode = extractMin(minHeap);
		int u=minHeapNode->v; //store the vertex number
		struct AdjListNode* adj=graph->array[u].head;
		while(adj!=NULL)
		{
			int v=adj->dest;
			if(isinMinHeap(minHeap,v) && adj->weight<key[v])
			{
				key[v]=adj->weight;
				parent[v]=u;
				decreaseKey(minHeap, v, key[v]);
			}
			adj=adj->next;
		}
	}
	printArr(parent, v);
}

int main()
{
 int v = 9; 
    struct Graph* graph = createGraph(v); 
    addEdge(graph, 0, 1, 4); 
    addEdge(graph, 0, 7, 8); 
    addEdge(graph, 1, 2, 8); 
    addEdge(graph, 1, 7, 11); 
    addEdge(graph, 2, 3, 7); 
    addEdge(graph, 2, 8, 2); 
    addEdge(graph, 2, 5, 4); 
    addEdge(graph, 3, 4, 9); 
    addEdge(graph, 3, 5, 14); 
    addEdge(graph, 4, 5, 10); 
    addEdge(graph, 5, 6, 2); 
    addEdge(graph, 6, 7, 1); 
    addEdge(graph, 6, 8, 6); 
    addEdge(graph, 7, 8, 7); 
  
    PrimMST(graph); 
  
    return 0; 
}
