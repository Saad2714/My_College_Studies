// C program to insert a node in AVL tree
#include<stdio.h>
#include<stdlib.h>

// An AVL tree node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
	int height;
        int index;
        int max_i;
};

// A utility function to get maximum of two integers
int max(int a, int b);

// A utility function to get the height of the tree
int height(struct Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
	return (a > b)? a : b;
}

/* Helper function that allocates a new node with the given key and
	NULL left and right pointers. */
int max3(int a, int b, int c)
{
if(a>=b&&a>=c)
return a;
else if(b>=a&&b>=c)
return b;
else if(c>=a&&c>=b)
return c;
}
struct Node* newNode(int key,int index)
{

	struct Node* node = (struct Node*)
						malloc(sizeof(struct Node));
	node->key = key;
        node->index=index;
        node->max_i=index;
	node->left = NULL;
	node->right = NULL;
	node->parent=NULL;
	node->height = 0; // new node is initially added at leaf
	return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	// Return new root
	return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

struct Node* max_index(struct Node* root)
{
if(root!=NULL)
{
max_index(root->left);
max_index(root->right);
if(root->left!=NULL&&root->right!=NULL)
{
root->max_i=max3(root->index,root->left->max_i,root->right->max_i);
//root->left->parent=root;
//root->right->parent=root;
}
else if(root->left!=NULL){
root->max_i=max(root->index,root->left->max_i);
//root->left->parent=root;
}
else if(root->right!=NULL)
{
root->max_i=max(root->index,root->right->max_i);
//root->right->parent=root;
}
}
return root;
}
struct Node* search(struct Node* root,int x)
{
	while(x!=root->key)
	{
		if(x>root->key)
		root=root->right;
		else
		root=root->left;
	}
	return root;
}
struct Node* insert(struct Node* node, int key,int index)
{

	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return(newNode(key,index));

	if (key < node->key)
		node->left = insert(node->left, key,index);
	else if (key > node->key)
		node->right = insert(node->right, key,index);
	else // Equal keys are not allowed in BST
		return node;


	node->height = 1 + max(height(node->left),
						height(node->right));


	int balance = getBalance(node);


	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}


	return node;
}

void preOrder(struct Node *root)
{
	if(root != NULL)
	{
		printf("%d %d \n", root->key,root->max_i);
		preOrder(root->left);
		preOrder(root->right);
	}
}

struct Node * minValueNode(struct Node* node)
{
    struct Node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}


struct Node* deleteNode(struct Node* root, int key)
{
    if (root == NULL)
        return root;

    if ( key < root->key )
        root->left = deleteNode(root->left, key);


    else if( key > root->key )
        root->right = deleteNode(root->right, key);

    else
    {

        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct Node *temp = root->left ? root->left :
                                             root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of
                            // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            struct Node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
      return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
void buildavl(struct Node** root,int a[],int n)
{
for(int i=0;i<n;i++)
{
*root=insert(*root,a[i],i);
}
}
int get_val_index(int a[],int i)
{
	return a[i];
}
int RBMax(struct Node* root,int x)
{
	struct Node* temp=root;
	struct Node* r=search(root,x);
	int maxj=r->right->max_i;
	/* do {
		if(temp->parent->left==temp)
		{
			maxj=max(max,j)
		}
	} while(temp!=root);*/
	return maxj;
}

int main()
{
  struct Node *root = NULL;
  int a[10]={1,2,3,4,5,6,7,8,9,10};
  buildavl(&root,a,10);
  root=max_index(root);

    printf("Preorder traversal of the constructed AVL "
           "tree is \n");
    preOrder(root);
		int i=7;
		int j=RBMax(root,get_val_index(a,i));
		printf("RBmax of %d is %d\n",i,j);

    return 0;
}
