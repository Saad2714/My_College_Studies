SinglyLinkedListNode* reverse(SinglyLinkedListNode*head)

{

SinglyLinkedListNode *temp_1=head;

while(temp_1->next!=NULL)

temp_1=temp_1->next;

SinglyLinkedListNode *temp=head;

if(temp->next->next==NULL)

temp->next->next=temp;

else

{

reverse(temp->next);

temp->next->next=temp;

}

head->next=NULL;

return temp_1;

}

