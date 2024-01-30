# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = None
        next_node = head

        while(next_node):
            temp_node = next_node.next
            next_node.next = curr
            curr = next_node
            next_node = temp_node
        return curr