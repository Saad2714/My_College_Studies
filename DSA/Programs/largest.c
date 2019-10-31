#include"stack.h"
#include<stdio.h>
int main(void)
{
	int arr[5];
	for(int i=0;i<5;i++)
	{
		scanf("%d",&arr[i]);
	}
	int brr[5];
	struct stack* stack = createStack(5);
	push(stack,0);
	for(int i=1;i<5;i++)
	{
		if(arr[i]>arr[stack->data[stack->top]])
			push(stack,i);
		else 
		{
			for(int j=stack->top;arr[i]<arr[stack->data[j]] && isEmpty(stack)==0;)
			{
				pop(stack);
				j=stack->top;
			}
			push(stack,i);	
		}
	}
	int p=4;
	for(int i=stack->data[stack->top];i>=0;i--)
	{
		if(i!=stack->data[stack->top-1] || (i==0 && stack->top==0))
		{
			brr[p--]=arr[stack->data[stack->top]];
		}	
		else if(stack->top!=0)
		{
			brr[p--]=arr[stack->data[stack->top-1]];
			pop(stack);
		}
	}
	for(int i=0;i<5;i++)
	{
		printf("%d ",brr[i]);
	}
	return 0;
}

