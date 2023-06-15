# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        min_diff = 99999999
        curr_node = root
        prev_node = None
        node_stk = []
        while curr_node != None or len(node_stk) != 0:
            if curr_node != None:
                node_stk.append(curr_node)
                curr_node = curr_node.left
            else:
                curr_node = node_stk.pop()
                if prev_node != None:
                    min_diff = min(min_diff, curr_node.val - prev_node.val)

                prev_node = curr_node
                curr_node = curr_node.right


        return min_diff

        