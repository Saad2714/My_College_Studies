# Python program to find maximum  
# sum of a node and its children 
class newNode():  
  
    def __init__(self, data):  
        self.data = data 
        self.left = None
        self.right = None
  
def maxSum(root): 
  
    if (root == None): 
        return 0
  
    res = maxSum(root.left)  
  
    # if left and right link are None then  
    # add all the three Node  
    if (root.left != None and root.right != None): 
        sum = root.data + root.left.data + root.right.data  
        res = max(res, sum)  
  
    return max(res, maxSum(root.right))  
      
# Driver code  
if __name__ == '__main__': 
    root = newNode(15)  
    root.left = newNode(16)  
    root.left.left = newNode(8)  
    root.left.left.left = newNode(55)  
    root.left.right = newNode(67)  
    root.left.right.left = newNode(44)  
    root.right = newNode(17)  
    root.right.left = newNode(7)  
    root.right.left.right = newNode(11)  
    root.right.right = newNode(41)  
    print(maxSum(root)) 
  
