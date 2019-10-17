#include<stdio.h>
#include<stdlib.h>

struct node{
    int key,height,level;
    struct node *lc, *rc, *parent;
};
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

int main()
{
    int n;
    scanf("%d",&n);
    char arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%s",&arr[i]);
    }
    
}
