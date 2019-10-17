#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
int traverse(struct node *head);

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

    traverse(head);
}

int traverse(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d\n",temp -> data);
        temp = temp -> next;
    }
    printf("End of linked list\n");
}
