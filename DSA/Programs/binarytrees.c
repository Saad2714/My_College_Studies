#include<stdio.h>
#include<stdlib.h>
#define MAX_ARR_SIZE 1000000
void swap(int* arr, int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int partition(int* arr, int start, int end, int pivotIndex)
{
	if(end > start)
	{
		swap(arr, end, pivotIndex);
		pivotIndex = end;
		int rightStart = start;
		while(rightStart < pivotIndex)
		{
			if(arr[rightStart] > arr[pivotIndex])
			{
				break;
			}
			rightStart++;
		}
		if(rightStart < pivotIndex)
		{
			int toCheck= rightStart+1;
			while(toCheck < pivotIndex)
			{
				if(arr[toCheck] <= arr[pivotIndex])
				{
					swap(arr, rightStart++, toCheck);
				}
				toCheck++;
			}
			swap(arr, rightStart, pivotIndex);
			pivotIndex = rightStart;
		}
	}
	return pivotIndex;
}

void quickSort(int* arr, int start, int end)
{
	if(end > start)
	{
		int pivotIndex = end;
		pivotIndex = partition(arr, start, end, pivotIndex);
		if(pivotIndex > start)
		{
			quickSort(arr, start, pivotIndex-1);
		}
		if(pivotIndex < end)
		{
			quickSort(arr, pivotIndex+1, end);
		}
	}
}
//----------------------Above is qsort, below is BST code---------------------------------------------------------

int max(int a, int b)
{
	return (a > b) ? a : b;
}

struct node
{
	int data, level, height;
	struct node *left, *right, *parent;
};

struct node* buildBST(int* arr, int begin, int end, struct node* parent)
{
	if(begin <= end)
	{
		int k = (begin + end)/2;
		struct node* curr = (struct node*) malloc(sizeof(struct node));
		curr->data = arr[k];
		curr->parent = parent;
		if(k - 1 >= begin)
		{
			curr->left = buildBST(arr, begin, k-1, curr);
		}
		else
		{
			curr->left = NULL;
		}
		if(k + 1 <= end)
		{
			curr->right = buildBST(arr, k+1, end, curr);
		}
		else
		{
			curr->right = NULL;
		}
		return curr;
	}
	return NULL;
}

void preOrder(struct node* root)
{
	printf("%d ", root->data);
	if(root->left != NULL)
	{
		preOrder(root->left);
	}
	if(root->right != NULL)
	{
		preOrder(root->right);
	}
}

void inOrder(struct node* root)
{
	if(root->left != NULL)
	{
		inOrder(root->left);
	}
	printf("%d ", root->data);
	if(root->right != NULL)
	{
		inOrder(root->right);
	}
}

void postOrder(struct node* root)
{
	
	if(root->left != NULL)
	{
		postOrder(root->left);
	}
	if(root->right != NULL)
	{
		postOrder(root->right);
	}
	printf("%d ", root->data);
}

void level(struct node* root)
{
	if(root->parent == 0)
	{
		root->level = 0;
	}
	else
	{
		root->level = root->parent->level + 1;
	}
	if(root->left != NULL)
	{
		level(root->left);
	}
	if(root->right != NULL)
	{
		level(root->right);
	}
}

int height(struct node* root)
{
	if(root->left == NULL && root->right == NULL)
	{
		root->height = 0; 
	}
	else if(root->left == NULL)
	{
		root->height = height(root->right) + 1;
	}
	else if(root->right == NULL)
	{
		root->height = height(root->left) + 1;
	}
	else
	{
		root->height = max(height(root->left), height(root->right)) + 1;
	}
	return root->height;
}

void levelOrder(struct node* mainroot)
{
	struct node* queue[1000];
	int head = 0;
	int tail = 0;
	queue[tail] = mainroot;
	struct node* root = queue[head];
	while(head <= tail)
	{
		root = queue[head++];
		printf("%d %d %d\n", root->level, root->height, root->data);
		if(root->left != NULL)
		{
			queue[++tail] = root->left;
		}
		if(root->right != NULL)
		{
			queue[++tail] = root->right;
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int arr[MAX_ARR_SIZE];
	for(int i = 0; i < n; i++)
	{
		arr[i] = rand()%(100*n);
	}
	quickSort(arr, 0, n-1);
	printf("Array: ");
	for(int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);		
	}
	printf("\n");

	struct node* root = buildBST(arr, 0, n-1, NULL);
	printf("Preorder: ");
	preOrder(root);
	printf("\n");
	printf("Postorder: ");
	postOrder(root);
	printf("\n");
	printf("Inorder: ");
	inOrder(root);
	printf("\n");
	level(root);
	printf("Level success\n");
	height(root);
	printf("Height success\n");
	levelOrder(root);
	return 0;
}
