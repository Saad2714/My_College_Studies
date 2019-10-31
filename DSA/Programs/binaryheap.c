#include<stdio.h>
#include<stdlib.h>
#define MAX_ARR_SIZE 1000000


int index_of_min(int* arr, int a, int b)
{
	return (arr[a] < arr[b])? a: b;
}

void swap(int* arr, int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void bottomUpHeapify(int *arr, int n, int i)
{
	if(i >= 0 && i < n)
	{
		if((i - 1)/2 >= 0)
		{
			if((arr[i] < arr[(i - 1)/2]))
			{
				swap(arr, i, (i - 1)/2);
				bottomUpHeapify(arr, n, (i - 1)/2);
			}	
		}
	}
}

void topDownHeapify(int *arr, int n, int i)
{
	int temp = i;
	if(i >= 0 && i < n)
	{
		if(2*i + 2 < n)
		{
			temp = index_of_min(arr,2*i + 1, 2*i + 2);
		}
		else if(2*i + 1 < n)
		{
			temp = 2*i + 1;
		}
		if (arr[i] > arr[temp])
		{
			swap(arr, i, temp);
			topDownHeapify(arr, n, temp);
		}
	}
}

int min(int* arr, int n)
{
	if(n > 0)
	{
		return arr[0];
	}
}

int deleteMin(int* arr, int* nptr)
{
	if(*nptr > 0)
	{
		int temp = arr[0];
		arr[0] = arr[--(*nptr)];
		topDownHeapify(arr, *nptr, 0);
		return temp;
	}
	return 0;
}

void changeKey(int* arr,int n, int i, int change)
{
	arr[i] += change;
	if(change > 0)
	{
		topDownHeapify(arr, n, i);
	}
	else if(change < 0)
	{
		bottomUpHeapify(arr, n, i);
	}
}

void add(int* arr, int* nptr, int toAdd)
{
	arr[(*nptr)++] = toAdd;
	bottomUpHeapify(arr, *nptr, *nptr - 1);
}

void buildHeap(int* arr, int n)
{
	if(n > 0)
	{
		for(int i = n/2; i >= 0; i--)
		{
			topDownHeapify(arr, n, i);
		}
	}
}

void heapSort(int* arr, int n)
{
	if(n > 0)
	{
		swap(arr, 0, n-1);
		topDownHeapify(arr, n-1, 0);
		heapSort(arr, n-1);
	}
}

int* heapUnion(int* arr1, int* arr2, int n1, int n2, int* n3ptr)
{
	int* arr3 = (int*) malloc(sizeof(int)*(n1 + n2));
	for(int i = 0; i < n1; i++)
	{
		arr3[i] = arr1[i];
	}
	for(int i = 0; i < n2; i++)
	{
		arr3[n1 + i] = arr2[i];
	}
	buildHeap(arr3, n1 + n2);
	*n3ptr = n1 + n2;
	return arr3;
}

int main()
{
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	int arr1[n1];
	int arr2[n2];
	for(int i = 0; i < n1; i++)
	{
		scanf("%d",arr1+i);
	}
	buildHeap(arr1, n1);
	for(int i = 0; i < n2; i++)
	{
		scanf("%d",arr2+i);
	}
	buildHeap(arr2, n2);
	for(int i = 0; i < n1; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	for(int i = 0; i < n2; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");
	int* arr3;
	int n3;
	arr3 = heapUnion(arr1, arr2, n1, n2, &n3);
	for(int i = 0; i < n3; i++)
	{
		printf("%d ", arr3[i]);
	}
	printf("\n");
	return 0;
}


