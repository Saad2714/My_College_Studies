#include<stdio.h>
#include<stdlib.h>
struct Node{
	char data;
	struct Node *next;
};
void push(struct Node **head_ref, char new_data){
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}
void pop(struct Node **head_ref){
	if(*head_ref == NULL){
		printf("NOTHING TO DELETE!\n");
		return;
	}
	struct Node *temp = *head_ref;
	*head_ref = temp->next;
	free(temp);
}
int validstr(char str[], struct Node **head_ref){
	for(int i = 0; str[i] != '\0'; i++)
		if(str[i] == '(')
			push(head_ref, '(');
		else if(str[i] == ')'){
			if(*head_ref == NULL)
				return 0;
			pop(head_ref);
		}else
			printf("Not a valid string!\n");
	if(*head_ref != NULL)
		return 0;
	return 1;
}
int main(){
	struct Node *head = NULL;
	char str[100];
	printf("Enter string : ");
	scanf("%s", str);
	if(validstr(str, &head))
		printf("Given string is valid!\n");
	else 
		printf("Given string is invalid!\n");    
	return 0;
}
