# Python program to find height using parent array 
  
# This functio fills depth of i'th element in parent[] 
# The depth is filled in depth[i] 
  
def fillDepth(parent, i , depth): 
      
    # If depth[i] is already filled 
    if depth[i] != 0: 
        return 
      
    # If node at index i is root 
    if parent[i] == -1: 
        depth[i] = 1
        return 
  
    # If depth of parent is not evaluated before, 
    # then evaluate depth of parent first 
    if depth[parent[i]] == 0: 
        fillDepth(parent, parent[i] , depth) 
  
    # Depth of this node is depth of parent plus 1 
    depth[i] = depth[parent[i]] + 1
  
# This function reutns height of binary tree represented 
# by parent array 
def findHeight(parent): 
    n = len(parent)   
    # Create an array to store depth of all nodes and  
    # initialize depth of every node as 0 
    # Depth of root is 1 
    depth = [0 for i in range(n)] 
  
    # fill depth of all nodes 
    for i in range(n): 
        fillDepth(parent, i, depth) 
  
    # The height of binary tree is maximum of all  
    # depths. Find the maximum in depth[] and assign  
    # it to ht 
    ht = depth[0] 
    for i in range(1,n): 
        ht = max(ht, depth[i]) 
  
    return ht 
  
# Driver program to test above function 
parent = [-1 , 0 , 0 , 1 , 1 , 3 , 5] 
print "Height is %d" %(findHeight(parent)) 
  
