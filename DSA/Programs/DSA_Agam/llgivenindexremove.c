#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
void viewlinkedlist(struct node *head);
void delete(struct node **head, int index);

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

struct node *delete(struct node *head, int index)
{
    if(index == 0)
    {
        if(head-> next != NULL)
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp = head;
            head = head -> next;
            free(temp);
            return head;

        }
        else
        {
            printf("Empty Linked List\n");
            exit();

        }
    }
    
}
