#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
void add(struct node **head, int position, int data);
void viewlinkedlist(struct node *head);

int main()
{
    //n -> number of edges
    int n;
    scanf("%d",&n)
    //insert edge list
    for(int i=0;i<n;i++)
    {
        
    }
}
void add(struct node **head, int position, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp = *head;
    int count =0;
    while(1)
    {
        if(position == 0 )
            break;
        else
        {
            count ++;
            if(count == position)
                break;
            temp = temp -> next;
        }
    }
    if (temp -> next == NULL && count != 0)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new -> data = data;
        temp -> next = new;
        new -> next = NULL;
    }
    else if(count == 0)
    {
        if(temp -> next == NULL)
            temp -> data = data;
        else
        {
            struct node *new = (struct node *)malloc(sizeof(struct node));
            new -> data = data;
            new -> next = temp;
            *head = new;
        }
    }
    else
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new -> data = data;
        new -> next = temp -> next;
        temp -> next = new;
    }
}
void viewlinkedlist(struct node *head)
{
    while(head != NULL)
    {
        printf("%d->",head->data);
        head = head -> next;
    }

    printf("NULL\n");
}
