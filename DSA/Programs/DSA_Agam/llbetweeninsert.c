#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void viewlinkedlist(struct node *head);
void betweeninsert(struct node *prev_head,int data);
/* void betweeninsert(struct node **prev_head,int data); */
    
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
    betweeninsert(second , new_data);
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
void betweeninsert(struct node *prev_head,int new_data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> next = prev_head -> next;
    prev_head -> next = temp;
    temp -> data = new_data;
}

/* struct node *betweeninsert(struct node *prev_node, int new_data) 
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if(prev_head == NULL)
    {

    }
} */
