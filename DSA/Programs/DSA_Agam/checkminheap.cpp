#include <iostream>
using namespace std;

// Function to check if given array represents Min-Heap or not
bool checkMinHeap(int A[], int i, int n)
{
	// if i is a leaf node, return true as every leaf node is a heap
	if (2*i + 2 > n)
		return true;

	// if i is an internal node		

	// recursively check if left child is heap
	bool left = (A[i] <= A[2*i + 1]) && checkMinHeap(A, 2*i + 1, n);
	
	// recursively check if right child is heap (to avoid array out
	// of bound, we first check if right child exists or not)
	bool right = (2*i + 2 == n) || 
				(A[i] <= A[2*i + 2] && checkMinHeap(A, 2*i + 2, n));
	
	// return true if both left and right child are heap
	return left && right;
}

// main function
int main()
{
	int A[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(A) / sizeof(int);

	// start with index 0 (root of the heap)
	int index = 0;
	
	if (checkMinHeap(A, index, n))
		cout << "Given array is a min heap";
	else
		cout << "Given array is not a min heap";
	
	return 0;
}
