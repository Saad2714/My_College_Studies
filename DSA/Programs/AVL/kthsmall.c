#include <stdio.h> 
#include <stdlib.h> 

#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0]) 

/*The idea is to maintain rank of each node. We can keep track of elements in a subtree of any node while building the tree. Since we need K-th smallest element, we can maintain number of elements of left subtree in every node.

Assume that the root is having N nodes in its left subtree. If K = N + 1, root is K-th node. If K < N, we will continue our search (recursion) for the Kth smallest element in the left subtree of root. If K > N + 1, we continue our search in the right subtree for the (K – N – 1)-th smallest element. Note that we need the count of elements in left subtree only.
typedef struct node_t node_t; 

/* Binary tree node */

struct node_t 
{ 
	int data; 
	int lCount; 

	node_t* left; 
	node_t* right; 
}; 

/* Iterative insertion 
Recursion is least preferred unless we gain something 
*/
node_t *insert_node(node_t *root, node_t* node) 
{ 
	/* A crawling pointer */
	node_t *pTraverse = root; 
	node_t *currentParent = root; 

	// Traverse till appropriate node 
	while(pTraverse) 
	{ 
		currentParent = pTraverse; 

		if( node->data < pTraverse->data ) 
		{ 
			/* We are branching to left subtree 
			increment node count */
			pTraverse->lCount++; 
			/* left subtree */
			pTraverse = pTraverse->left; 
		} 
		else
		{ 
			/* right subtree */
			pTraverse = pTraverse->right; 
		} 
	} 

	/* If the tree is empty, make it as root node */
	if( !root ) 
	{ 
		root = node; 
	} 
	else if( node->data < currentParent->data ) 
	{ 
		/* Insert on left side */
		currentParent->left = node; 
	} 
	else
	{ 
		/* Insert on right side */
		currentParent->right = node; 
	} 

	return root; 
} 

/* Elements are in an array. The function builds binary tree */
node_t* binary_search_tree(node_t *root, int keys[], int const size) 
{ 
	int iterator; 
	node_t *new_node = NULL; 

	for(iterator = 0; iterator < size; iterator++) 
	{ 
		new_node = (node_t *)malloc( sizeof(node_t) ); 

		/* initialize */
		new_node->data = keys[iterator]; 
		new_node->lCount = 0; 
		new_node->left = NULL; 
		new_node->right = NULL; 

		/* insert into BST */
		root = insert_node(root, new_node); 
	} 

	return root; 
} 

int k_smallest_element(node_t *root, int k) 
{ 
	int ret = -1; 

	if( root ) 
	{ 
		/* A crawling pointer */
		node_t *pTraverse = root; 

		/* Go to k-th smallest */
		while(pTraverse) 
		{ 
			if( (pTraverse->lCount + 1) == k ) 
			{ 
				ret = pTraverse->data; 
				break; 
			} 
			else if( k > pTraverse->lCount ) 
			{ 
				/* There are less nodes on left subtree 
					Go to right subtree */
				k = k - (pTraverse->lCount + 1); 
				pTraverse = pTraverse->right; 
			} 
			else
			{ 
				/* The node is on left subtree */
				pTraverse = pTraverse->left; 
			} 
		} 
	} 

	return ret; 
} 

/* Driver program to test above functions */
int main(void) 
{ 
	/* just add elements to test */
	/* NOTE: A sorted array results in skewed tree */
	int ele[] = { 20, 8, 22, 4, 12, 10, 14 }; 
	int i; 
	node_t* root = NULL; 

	/* Creating the tree given in the above diagram */
	root = binary_search_tree(root, ele, ARRAY_SIZE(ele)); 

	/* It should print the sorted array */
	for(i = 1; i <= ARRAY_SIZE(ele); i++) 
	{ 
		printf("\n kth smallest elment for k = %d is %d", 
				i, k_smallest_element(root, i)); 
	} 

	getchar(); 
	return 0; 
} 

