#include<stdio.h>
#include<stdlib.h>

void sort(int a[], int m, int n);
void merge(int a[], int m, int n, int k);
struct node *buildBST(int a[], int i,int j, struct node *parent);
void preorder(struct node *head);
void postorder(struct node *head);
void inorder(struct node *head);
void level(struct node *head, int l);
int height(struct node *head);
int max(int a, int b);

struct node{
    int key,height,level;
    struct node *lc, *rc, *parent;
};

int main()
{
    int n=6,a[6] = {10, 5, 1, 7, 40, 50};
    /*
    for(int i=0;i<n;i++)
    {
        a[i] = rand()%(10);
        printf("%d ",a[i]);
    }
    printf("\n");
    */
    sort(a,0,n);
    struct node *BST = (struct node *)malloc(sizeof(struct node)); 
    BST = buildBST(a,0,n-1,NULL);
    printf("preorder : ");
    preorder(BST);
    printf("\n");
    printf("postorder : ");
    postorder(BST);
    printf("\n");
    printf("inorder : ");
    inorder(BST);
    printf("\n");
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

void preorder(struct node *head)
{
    struct node *x = (struct node *)malloc(sizeof(struct node));
    x = head;
    if(x != NULL)
    {
        printf("%d ",x->key);
        preorder(x->lc);
        preorder(x->rc);
    }
}

void postorder(struct node *head)
{
    struct node *x = (struct node *)malloc(sizeof(struct node));
    x = head;
    if(x != NULL)
    {
        postorder(x->lc);
        postorder(x->rc);
        printf("%d ",x->key);
    }
}

void inorder(struct node *node)
{
    /*
    struct node *x = (struct node *)malloc(sizeof(struct node));
    x = head;
    if(x != NULL)
    {
        inorder(x->lc);
        printf("%d ",head->key);
        inorder(x->rc);
    }
    */
    if (node == NULL)
        return;
    inorder(node->lc);
    printf("%d ", node->key);
    inorder(node->rc);
}

void level(struct node *head, int l)
{
    struct node *x = (struct node *)malloc(sizeof(struct node));
    x = head;
    if(x!=NULL)
    {
        x->level = l;
        level(x->lc,l+1);
        level(x->rc,l+1);
    }
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
void levelorder(struct node *head)
{

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
int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}
