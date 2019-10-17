#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
int inserthead(struct node **head, int new_data);
/* struct node *inserthead(struct node *head, int new_data); */
void viewlinkedlist(struct node *head);

int main()
{
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;
    struct node *tail = NULL;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    tail = (struct node *)malloc(sizeof(struct node));

    head -> data = 1;
    head -> next = second;

    second -> data = 2;
    second -> next = third;

    third -> data = 3;
    third -> next = tail;

    tail -> data = 4;
    tail -> next = NULL;
    
    int new_data = 10;
    inserthead(&head,new_data);
    /* inserthead(head,new_data); */
    viewlinkedlist(head);
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
int inserthead(struct node **head,int new_data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    
    new -> data = new_data;
    new -> next = *head;    
    *head = new;
}
/*
struct node *inserthead(struct node *head, int new_data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new -> data = new_data;
    new -> next = head;

    *head = *new;

    return head;
}
*/
