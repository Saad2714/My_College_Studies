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
    struct node *head = (struct node *)malloc(sizeof(struct node));

    add(&head,0,1);
    add(&head,1,2);
    add(&head,2,3);
    add(&head,3,4);
    viewlinkedlist(head);
    add(&head,0,10);
    add(&head,1,9);
    viewlinkedlist(head);
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
