#include<bits/stdc++.h>
using namespace std;
struct node
{
    int key,h,l;
    node *lc,*rc,*p;
};
node* BuildBST(int ar[],int start,int end,node* parent)
{
    if(start==end)
    {
        node ptr=(node)malloc(sizeof(node));
        ptr->key=ar[start];  
        ptr->lc=NULL;
        ptr->rc=NULL;
        ptr->p=parent;  
        return ptr;    
    }
    else if(start<end)
    {
        int mid=(start+end)/2;
        node ptr=(node)malloc(sizeof(node));
        ptr->key=ar[mid];
        ptr->p=parent;
        ptr->lc=BuildBST(ar,start,mid-1,ptr);
        ptr->rc=BuildBST(ar,mid+1,end,ptr);
        return ptr;
    }
    else
    {
        return NULL;
    }     
}
void preorder(node* head)
{
    if(head!=NULL)
    {
        cout<<head->key<<" ";
        preorder(head->lc);
        preorder(head->rc);
    }
}
void postorder(node* head)
{
    if(head!=NULL)
    {
        postorder(head->lc);
        postorder(head->rc);
        cout<<head->key<<" ";
    }
}
void inorder(node* head)
{
    if(head!=NULL)
    {
        inorder(head->lc);
        cout<<head->key<<" ";
        inorder(head->rc);
    }
}
void level(node* head,int ll)
{
    if(head!=NULL)
    {
        head->l=ll;
        level(head->lc,ll+1);
        level(head->rc,ll+1);
    }
}
void height(node* head)
{
    if(head->lc==NULL && head->rc==NULL)
    {
        head->h=0;
    }
    else if(head->lc==NULL && head->rc!=NULL)
    {
        height(head->rc);
        head->h=head->rc->h+1;
    }
    else if(head->lc!=NULL && head->rc==NULL)
    {
        height(head->lc);
        head->h=head->lc->h+1;
    }
    else
    {
        height(head->lc);
        height(head->rc);
        head->h=max(head->lc->h,head->rc->h)+1;
    }    
}
void level_order(queue<node*> q)
{
    
}
int main()
{
    int ar[5] = {2,3,5,6,7} 
    node* head=BuildBST(ar,0,4,NULL);
    preorder(head);

}
