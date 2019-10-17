#include <stdio.h>
#include <stdlib.h>

struct node {
   int key,height,level; 
	
   struct node *lc, *rc, *parent;
};

struct node *root = NULL;

int max (int a, int b)
{
  if(a>b)
    return a;
  else
    return b;
}
void insert(int key) {
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;

   tempNode->key = key;
   tempNode->lc = NULL;
   tempNode->rc = NULL;

   //if tree is empty
   if(root == NULL) {
      root = tempNode;
   } else {
      current = root;
      parent = NULL;

      while(1) { 
         parent = current;
         
         //go to left of the tree
         if(key < parent->key) {
            current = current->lc;                
            
            //insert to the left
            if(current == NULL) {
               parent->lc = tempNode;
               return;
            }
         }  //go to right of the tree
         else {
            current = current->rc;

            //insert to the right
            if(current == NULL) {
               parent->rc = tempNode;
               return;
            }
         }
      }            
   }
}

struct node* search(int key) {
   struct node *current = root;
   printf("Visiting elements: ");

   while(current->key != key) {
      if(current != NULL)
         printf("%d ",current->key); 

      //go to left tree
      if(current->key > key) {
         current = current->lc;
      }
      //else go to right tree
      else {                
         current = current->rc;
      }

      //not found
      if(current == NULL) {
         return NULL;
      }
   }
   
   return current;
}

void pre_order_traversal(struct node* root) {
   if(root != NULL) {
      printf("%d ",root->key);
      pre_order_traversal(root->lc);
      pre_order_traversal(root->rc);
   }
}

void inorder_traversal(struct node* root) {
   if(root != NULL) {
      inorder_traversal(root->lc);
      printf("%d ",root->key);          
      inorder_traversal(root->rc);
   }
}
void inorder_level(struct node* root) {
   if(root != NULL) {
      inorder_level(root->lc);
      printf("%d ",root->level);          
      inorder_level(root->rc);
   }
}
void inorder_height(struct node* root) {
   if(root != NULL) {
      inorder_height(root->lc);
      printf("%d ",root->height);          
      inorder_height(root->rc);
   }
}

void post_order_traversal(struct node* root) {
   if(root != NULL) {
      post_order_traversal(root->lc);
      post_order_traversal(root->rc);
      printf("%d ", root->key);
   }
}
struct node *buildBST(int a[], int i,int j, struct node *parent)
{
    struct node *x = (struct node *)malloc(sizeof(struct node));
    if(i<j)
    {
        int k = (i+j)/2;
        x->parent = parent;
        x->key = a[k];
        if(i<=k-1)
            x->lc = buildBST(a,i,k-1,x);
        else
            x->lc = NULL;

        if(k+1<= j)
            x->rc = buildBST(a,k+1,j,x);
        else
            x->rc = NULL;
    }
    else if(i==j)
    {
        struct node *x = (struct node *)malloc(sizeof(struct node));
        x->parent = parent;
        x->key = a[i];
        x->lc = NULL;
        x->rc = NULL;
        return x;
    }
    return x;
}

int Treelevel(struct node *head, int l)
{
    struct node *x = (struct node *)malloc(sizeof(struct node));
    x = head;
    int a;
    if(x!=NULL)
    {
        x->level = l;
        a = x->level;
        Treelevel(x->lc,l+1);
        Treelevel(x->rc,l+1);
    }
    return a;
}
int height(struct node *head)
{
    struct node *x = (struct node *)malloc(sizeof(struct node));
    x =  head;
    if(x->lc==NULL && x->rc==NULL)
    {
        x->height=0;
    }
    else if(x->lc==NULL && x->rc!=NULL)
    {
        height(x->rc);
        x->height=x->rc->height+1;
    }
    else if(x->lc!=NULL && x->rc==NULL)
    {
        height(x->lc);
        x->height=x->lc->height+1;
    }
    else
    {
        height(x->lc);
        height(x->rc);
        x->height=max(x->lc->height,x->rc->height)+1;
    }       
}

void merge(int a[],int m,int n,int k)
{
    int b[n-m+1];
    int l = m,r=k+1, p = 0;
    while(l<= k && r<=n ) 
    {
        if(a[l] <= a[r])
            b[p++] = a[l++];
        else if(a[l] > a[r])
            b[p++] = a[r++];
    }
    while(l<= k)
        b[p++] = a[l++];
    while(r<=n)
        b[p++] = a[r++];
    p=0;
    for(int i=m;i<=n;i++)
    {
        a[i] = b[p++];
    }
}

void sort(int a[], int m, int n)
{
    int mid = (m+n)/2;
    if(m<n)
    {
        sort(a,m,mid);
        sort(a,mid+1,n);
        merge(a,m,n,mid);
    }
}

int main() 
{
    int i;
    int array[7] = { 27, 14, 35, 10, 19, 31, 42 };

    for(i = 0; i < 7; i++)
        insert(array[i]);

    struct node *BST = (struct node *)malloc(sizeof(struct node ));
    BST = buildBST(array,0,6,NULL);
    printf("\nPreorder traversal: ");
    pre_order_traversal(root);

    printf("\nInorder traversal: ");
    inorder_traversal(root);

    printf("\nPost order traversal: ");
    post_order_traversal(root);
    printf("\n");
    int level =0;
    level = Treelevel(BST,level);
    printf("Inorder levels: ");
    inorder_level(BST);
    printf("\n");
    printf("level : %d\n",level);

    height(BST);
    printf("Inorder height: ");
    inorder_height(BST);
    printf("\n");
    /*
    i = 31;
    struct node * temp = search(i);

    if(temp != NULL) {
        printf("[%d] Element found.", temp->key);
        printf("\n");
    }else {
        printf("[ x ] Element not found (%d).\n", i);
    }

    i = 15;
    temp = search(i);

    if(temp != NULL) {
        printf("[%d] Element found.", temp->key);
        printf("\n");
    }else {
        printf("[ x ] Element not found (%d).\n", i);
    }            
    printf("\nPreorder traversal: ");
    pre_order_traversal(root);

    printf("\nInorder traversal: ");
    inorder_traversal(root);

    printf("\nPost order traversal: ");
    post_order_traversal(root);       
    */
    return 0;
}
