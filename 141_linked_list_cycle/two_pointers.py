# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if head == None:
            return False
        
        ptr = head
        ptr_skip = head.next

        while ptr_skip != None:
            if ptr == ptr_skip:
                return True

            ptr = ptr.next
            if ptr_skip.next == None:
                break
            
            ptr_skip = ptr_skip.next.next

        return False