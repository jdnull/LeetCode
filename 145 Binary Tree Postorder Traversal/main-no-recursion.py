class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def postorderTraversal(self, root):
    rList = []
    if root == None:
        return [];
    
    stack = []
	stack.append(root)
	while len(stack) != 0:
		topNode = stack[len(stack)-1]
		if topNode.left != None and topNode.left.val != None:
			stack.append(topNode.left)
			continue
		if topNode.right != None and topNode.right.val != None:
			stack.append(topNode.right)
			continue

		visitNode = stack.pop()
		rList.append(visitNode.val)
		visitNode.val = None
	return rList