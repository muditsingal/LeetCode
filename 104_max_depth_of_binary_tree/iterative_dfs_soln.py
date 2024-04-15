# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if None == root:
            return 0
        
        stack = [[root,1]]
        res = 1
        while stack:
            curr_node, depth = stack.pop()
            if curr_node != None:
                res = max(res, depth)
                stack.append([curr_node.left, depth+1])
                stack.append([curr_node.right, depth+1])

        return res
