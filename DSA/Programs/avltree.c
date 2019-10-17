#include<stdio.h>
#include<stdlib.h>
struct Node{
	int key;
	//struct Node *p;
	struct Node *lc;
	struct Node *rc;
	int desc;  //var to keep count of no of descending nodes
	int h;
};
int max(int a, int b)
{
	return (a>b)?a:b;
}
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->h;
}
struct Node* newNode(int key)
{
	struct Node* node=(struct Node*)malloc(sizeof(struct Node));
	node->key=key;
	node->lc=NULL;
	node->rc=NULL;
	node->h=1;
	node->desc=0;
	//node->p=root;
	return node;
}
struct Node* rightRotate(struct Node *y)//to rotate subtree rooted at y(making x root)
{
	struct Node *x=y->lc;
	struct Node *T2=x->rc;

	x->rc=y;
	//x->p=y->p;
	//y->p=x;
	y->lc=T2;
	//T2->p=y;

	y->h=max(height(y->lc),height(y->rc))+1;
	x->h=max(height(x->lc), height(x->rc))+1;

	int val=(T2!=NULL)?T2->desc:-1;
	y->desc=y->desc-(x->desc+1)+val+1;
	x->desc=x->desc-(val+1)+(y->desc+1);
	return x;
}

struct Node *leftRotate(struct Node *x)// to rotate subtree rooted at x(making y root)
{
	struct Node *y=x->rc;
	struct Node *T2=y->lc;

	y->lc=x;
	//y->p=x->p;
	//x->p=y;
	x->rc=T2;
	//T2->p=x;

	y->h=max(height(y->lc), height(y->rc))+1;
	x->h=max(height(x->lc), height(x->rc))+1;

	int val = (T2!=NULL)?T2->desc:-1;
	x->desc=x->desc-(y->desc+1)+val+1;
	y->desc=y->desc-(val+1)+(x->desc+1);

	return y;
}
int getBalance(struct Node *N)
{
	if(N==NULL)
		return 0;
	else
		return (height(N->lc)-height(N->rc));
}
struct Node* insert(struct Node* node, int key)
{
	if(node==NULL)
		return newNode(key);
	if(key<node->key){
		node->lc=insert(node->lc, key);
		node->desc++;
	}
	else if(key>node->key){
		node->rc=insert(node->rc, key);
		node->desc++;
	}
	else
		return node;
	
	node->h=1+max(height(node->lc), height(node->rc));

	int balance=getBalance(node);

	//4cases: 2 for zigzig, 2 zigzag
	//left left-zigzig
	if(balance>1 && key<node->lc->key)
		return rightRotate(node);
	//rightright
	if(balance<-1 && key>node->rc->key)
		return leftRotate(node);
	//leftright-zigzag
	if(balance>1 && key>node->lc->key)
	{
		node->lc= leftRotate(node->lc);
		return rightRotate(node);
	}
	//rightleft
	if(balance<-1 && key<node->rc->key)
	{
		node->rc=rightRotate(node->rc);
		return leftRotate(node);
	}
	return node;
}
struct Node * minValueNode(struct Node* node)
{
    struct Node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->lc != NULL)
        current = current->lc;

    return current;
}
struct Node* deleteNode(struct Node* root, int key)
{
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == NULL)
        return root;

    if ( key < root->key ){
        root->lc = deleteNode(root->lc, key);
	root->desc--;
    }

    else if( key > root->key ){
        root->rc = deleteNode(root->rc, key);
	root->desc--;
    }
    else
    {
        // node with only one child or no child
        if( (root->lc == NULL) || (root->rc == NULL) )
        {
            struct Node *temp = root->lc ? root->lc :
                                             root->rc;

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
            struct Node* temp = minValueNode(root->rc);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->rc = deleteNode(root->rc, temp->key);
	    root->desc--;
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
      return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->h = 1 + max(height(root->lc),
                           height(root->rc));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->lc) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->lc) < 0)
    {
        root->lc =  leftRotate(root->lc);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->rc) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->rc) > 0)
    {
        root->rc = rightRotate(root->rc);
        return leftRotate(root);
    }

    return root;
}
void inorder(struct Node* root)
{
	if(root!=NULL)
	{
		inorder(root->lc);
		printf("%d %d\n", root->key, root->h-1);
		inorder(root->rc);
	}
}
int main()
{
	struct Node* root=NULL;
	root = insert(root, 9); 
    	root = insert(root, 5); 
    	root = insert(root, 10); 
    	root = insert(root, 0); 
    	root = insert(root, 6); 
    	root = insert(root, 11); 
    	root = insert(root, -1); 
    	root = insert(root, 1); 
    	root = insert(root, 2); 
	inorder(root);
	root = deleteNode(root, 10);
	inorder(root);
	return 0;
}
