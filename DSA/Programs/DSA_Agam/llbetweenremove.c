#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
void viewlinkedlist(struct node *head);
void betweenremove(struct node *prev_node);
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
    betweenremove(second);
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
void betweenremove(struct node *prev_node)
{
    //method 1
    prev_node -> next = prev_node -> next -> next;
    //method2
    /*struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> next = prev_node -> next -> next;
    free(prev_node -> next);
    prev_node -> next = temp->next;*/
}
