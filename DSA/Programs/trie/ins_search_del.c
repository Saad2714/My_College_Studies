#include<stdio.h>
#include<stdlib.h>
struct node{
	int end_string;
	struct node *nextchar[26];
};
void insert(struct node *head, char str[], int n)
{
	int i,j;
	struct node *temp=head;
	for(i=0; i<n;i++)
	{
		if(temp->nextchar[str[i]-'a']==NULL)
		{
			struct node* n=(struct node*)malloc(sizeof(struct node));
			for(j=0;j<26; j++){
				n->nextchar[j]=NULL;
			}
			n->end_string=0;
			temp->nextchar[str[i]-'a']=n;
			temp=n;
		}
		else
			temp=temp->nextchar[str[i]-'a'];
	}
	temp->end_string=1;
}
int search(struct node *head, char str[], int n)
{
	int i;
	struct node *temp=head;
	for(i=0; i<n;i++)
	{
		if(temp->nextchar[str[i]-'a']==NULL)
			return 0;
		else
			temp=temp->nextchar[str[i]-'a'];
	}
	if(temp->end_string==1)
		return 1;
	else
		return 0;
}
int isempty(struct node *head)
{
	for(int i=0;i<26;i++)
	{
		if(head->nextchar[i]!=NULL)
			return 1;
	}
	return 0;
}
struct node* delete(struct node* head, char str[], int n,int depth)
{
	if(!head)
		return NULL;
	if(depth==n)	//if last char of str
	{
		if(head->end_string==1)
			head->end_string=0;
		if(isempty(head))
		{
			free(head);
			head=NULL;
		}
		return head;
	}
	//if not last index, recur for the the child
	int index=str[depth]-'a';
	head->nextchar[index]=delete(head->nextchar[index], str, n, depth+1);
	
	//if root does not have any child and its not the end of the word
	if(isempty(head) && head->end_string==0)
	{
		free(head);
		head=NULL;
	}
	return head;
}
int main()
{
	int n, m,i;
	struct node* head;
	for(i=0;i<26;i++)
		head->nextchar[i]=NULL;
	head->end_string=0;
	insert(head, "abcaabc", 7);
	insert(head, "abc", 3);
	search(head, "abc", 3);
	delete(head, "abc", 3,0);
	search(head, "abc", 3);
}
