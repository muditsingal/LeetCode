# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    trav_list = []

    def preorder_trav(self, curr):
        if curr == None:
            return
        
        self.trav_list.append(curr.val)
        self.preorder_trav(curr.left)
        self.preorder_trav(curr.right)
        
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.trav_list.clear()
        self.preorder_trav(root)
        return self.trav_list
        