# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
           return 0

        levels = 0
        q = [root]
        while q:

            for i in range(len(q)):
                curr_node = q.pop(0)
                if curr_node.left != None:
                    q.append(curr_node.left)
                if curr_node.right != None:
                    q.append(curr_node.right)

            levels += 1

        return levels
