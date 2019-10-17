#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to sort a K-Sorted Array
void sortKSortedArray(vector<int> &A, int k)
{
	// create an empty min heap using std::priority_queue
	// use std::greater as the comparison function for min-heap
	priority_queue<int, std::vector<int>, std::greater<int>> pq;

	int n = A.size();

	// insert first k+1 elements in the heap
	for (int i = 0; i <= k; i++) {
		pq.push(A[i]);
	}

	int index = 0;

	// do for remaining elements of the array
	for (int i = k + 1; i < n; i++)
	{
		// pop top element from min-heap and assign it to
		// next available array index
		A[index++] = pq.top();
		pq.pop();

		// push next array element into min-heap
		pq.push(A[i]);
	}

	// pop all remaining elements from the min heap and assign
	// it to next available array index
	while (!pq.empty())
	{
		A[index++] = pq.top();
		pq.pop();
	}
}

// main function
int main()
{
	vector<int> A = { 1, 4, 5, 2, 3, 7, 8, 6, 10, 9};
	int k = 2;

	sortKSortedArray(A, k);

	// print the sorted array
	for (int &i : A) {
		cout << i << " ";
	}

	return 0;
}
