# Python3 program to minimize subtree  
# Sum difference by one edge deletion  
  
# DFS method to traverse through edges,  
# calculating subtree Sum at each node and  
# updating the difference between subtrees  
def dfs(u, parent, totalSum, edge,  
                    subtree, res): 
    Sum = subtree[u]  
  
    # loop for all neighbors except parent  
    # and aggregate Sum over all subtrees 
    for i in range(len(edge[u])): 
        v = edge[u][i]  
        if (v != parent): 
            dfs(v, u, totalSum, edge,  
                        subtree, res)  
            Sum += subtree[v] 
  
    # store Sum in current node's  
    # subtree index  
    subtree[u] = Sum
  
    # at one side subtree Sum is 'Sum' and  
    # other side subtree Sum is 'totalSum - Sum'  
    # so their difference will be totalSum - 2*Sum,  
    # by which we'll update res  
    if (u != 0 and abs(totalSum - 2 * Sum) < res[0]): 
        res[0] = abs(totalSum - 2 * Sum) 
  
# Method returns minimum subtree  
# Sum difference  
def getMinSubtreeSumDifference(vertex, edges, N): 
    totalSum = 0
    subtree = [None] * N 
  
    # Calculating total Sum of tree  
    # and initializing subtree Sum's 
    # by vertex values 
    for i in range(N): 
        subtree[i] = vertex[i]  
        totalSum += vertex[i] 
  
    # filling edge data structure  
    edge = [[] for i in range(N)] 
    for i in range(N - 1): 
        edge[edges[i][0]].append(edges[i][1])  
        edge[edges[i][1]].append(edges[i][0]) 
  
    res = [999999999999]  
  
    # calling DFS method at node 0, 
    # with parent as -1  
    dfs(0, -1, totalSum, edge, subtree, res)  
    return res[0] 
  
# Driver Code 
if __name__ == '__main__': 
  
    vertex = [4, 2, 1, 6, 3, 5, 2] 
    edges = [[0, 1], [0, 2], [0, 3],  
             [2, 4], [2, 5], [3, 6]] 
    N = len(vertex)  
  
    print(getMinSubtreeSumDifference(vertex,  
                                     edges, N)) 
