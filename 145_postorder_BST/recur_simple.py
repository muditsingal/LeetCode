# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    node_list = []
    def postorder_trav(self, curr):
        if curr == None:
            return

        self.postorder_trav(curr.left)
        self.postorder_trav(curr.right)
        self.node_list.append(curr.val)

    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.node_list.clear()
        self.postorder_trav(root)
        return self.node_list