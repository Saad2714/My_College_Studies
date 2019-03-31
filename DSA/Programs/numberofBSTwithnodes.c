Total number of possible Binary Search Trees and Binary Trees with n keys

Total number of possible Binary Search Trees with n different keys (countBST(n)) = Catalan number Cn = (2n)!/(n+1)!*n!
For n = 0, 1, 2, 3, … values of Catalan numbers are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …. So are numbers of Binary Search Trees.

Total number of possible Binary Trees with n different keys (countBT(n)) = countBST(n) * n!

Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.



 

Below is code for finding count of BSTs and Binary Trees with n numbers. The code to find n’th Catalan number is taken from here.

C++JavaPython3C#PHP
filter_none
edit
play_arrow
brightness_4
// See https://www.geeksforgeeks.org/program-nth-catalan-number/ 
// for reference of below code. 
  
#include <bits/stdc++.h> 
using namespace std; 
  
// A function to find factorial of a given number 
unsigned long int factorial(unsigned int n) 
{ 
    unsigned long int res = 1; 
  
    // Calculate value of [1*(2)*---*(n-k+1)] / [k*(k-1)*---*1] 
    for (int i = 1; i <= n; ++i) 
    { 
        res *= i; 
    } 
  
    return res; 
} 
  
unsigned long int binomialCoeff(unsigned int n, unsigned int k) 
{ 
    unsigned long int res = 1; 
  
    // Since C(n, k) = C(n, n-k) 
    if (k > n - k) 
        k = n - k; 
  
    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1] 
    for (int i = 0; i < k; ++i) 
    { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
  
    return res; 
} 
  
  
// A Binomial coefficient based function to find nth catalan 
// number in O(n) time 
unsigned long int catalan(unsigned int n) 
{ 
    // Calculate value of 2nCn 
    unsigned long int c = binomialCoeff(2*n, n); 
  
    // return 2nCn/(n+1) 
    return c/(n+1); 
} 
  
// A function to count number of BST with n nodes  
// using catalan 
unsigned long int countBST(unsigned int n) 
{ 
    // find nth catalan number 
    unsigned long int count = catalan(n); 
  
    // return nth catalan number 
    return count; 
} 
  
// A function to count number of binary trees with n nodes  
unsigned long int countBT(unsigned int n) 
{ 
    // find count of BST with n numbers 
    unsigned long int count = catalan(n); 
  
    // return count * n! 
    return count * factorial(n); 
} 
  
// Driver Program to test above functions 
int main() 
{ 
  
    int count1,count2, n = 5; 
  
    // find count of BST and binary trees with n nodes 
        count1 = countBST(n); 
        count2 = countBT(n);  
      
    // print count of BST and binary trees with n nodes 
    cout<<"Count of BST with "<<n<<" nodes is "<<count1<<endl; 
        cout<<"Count of binary trees with "<<n<<" nodes is "<<count2; 
  
    return 0; 
} 
Output:

Count of BST with 5 nodes is 42
Count of binary trees with 5 nodes is 5040
Proof of Enumeration

Consider all possible binary search trees with each element at the root. If there are n nodes, then for each choice of root node, there are n – 1 non-root nodes and these non-root nodes must be partitioned into those that are less than a chosen root and those that are greater than the chosen root.

Let’s say node i is chosen to be the root. Then there are i – 1 nodes smaller than i and n – i nodes bigger than i. For each of these two sets of nodes, there is a certain number of possible subtrees.

Let t(n) be the total number of BSTs with n nodes. The total number of BSTs with i at the root is t(i – 1) t(n – i). The two terms are multiplied together because the arrangements in the left and right subtrees are independent. That is, for each arrangement in the left tree and for each arrangement in the right tree, you get one BST with i at the root.

Summing over i gives the total number of binary search trees with n nodes.

 t(n) = \sum_{i=1}^{n} t(i-1) t(n-i) 

The base case is t(0) = 1 and t(1) = 1, i.e. there is one empty BST and there is one BST with one node.

            t(2) = t(0)t(1) + t(1)t(0) = 2                             

            t(3) =t(0)t(2) +t(1)t(1) + t(2)t(0) = 2+1+2 = 5               

            t(4) = t(0)t(3) + t(1)t(2) +t(2)t(1)+ t(3)t(0) = 5+2+2+5 = 14                   

Also, the relationship countBT(n) = countBST(n) * n! holds. As for every possible BST, there can have n! binary trees where n is the number of nodes in BST.


