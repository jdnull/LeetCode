# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def preorderTraversal(self, root):
        if root == None:
            return []
        rList = []
        stack = [root]
        while len(stack) != 0:
            top = stack[len(stack)-1]
            rList.append(top.val)
            if top.left != None:
                stack.append(top.left)
                continue
            if top.right != None:
                stack.append(top.right)
                continue
            top = stack.pop()
            top = None
            
        return rList