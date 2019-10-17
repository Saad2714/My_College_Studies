#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next,*prev;
};

void doubleadd(struct node **head, int position , int data);
void viewlinkedlist(struct node *head);

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    
    doubleadd(&head,0,1);
    viewlinkedlist(head);
    doubleadd(&head,1,2);
    viewlinkedlist(head);
    doubleadd(&head,0,10);
    viewlinkedlist(head);
}

void doubleadd(struct node **head, int position, int data)
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
        new -> prev = temp;
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
            new -> prev = NULL;
            temp -> prev = new;
            *head = new;
        }
    }
    else
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new -> data = data;
        new -> next = temp -> next;
        new -> prev = temp;
        temp -> next -> prev = new;
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
