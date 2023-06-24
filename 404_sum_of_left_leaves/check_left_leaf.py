# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    sum_l_leaves = 0
    def traversal(self, curr):
        if curr == None:
            return

        if curr.left != None:
            if curr.left.left == None and curr.left.right == None:
                self.sum_l_leaves += curr.left.val

        self.traversal(curr.left)
        self.traversal(curr.right)

    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        self.traversal(root)
        return self.sum_l_leaves