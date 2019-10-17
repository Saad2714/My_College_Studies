#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
void viewlinkedlist(struct node *head);
void reverse (struct node **head);
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
    viewlinkedlist(head);
    reverse(&head);
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

void reverse(struct node **head)
{
    struct node *prev,*curr,*futu;
    prev = (struct node *)malloc(sizeof(struct node));
    curr = (struct node *)malloc(sizeof(struct node));
    futu = (struct node *)malloc(sizeof(struct node));
    
    prev = NULL;
    curr = *head;
    futu = NULL;

    while(curr != NULL)
    {
        futu = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = futu;
    }
    //This step is to change the head. Initially head was at 1. So, when we print it, the loop starts from 1 itself. Thus we need to change the position of head to the last one i.e. prev.
    *head = prev;
}
