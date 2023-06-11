# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        l1 = list1
        l2 = list2
        if l1 == None:
            head = l2
            return head
        elif l2 == None:
            head = l1
            return head

        if l1.val <= l2.val:
            head = ListNode(l1.val)
            l1 = l1.next

        elif l2.val < l1.val:
            head = ListNode(l2.val)
            l2 = l2.next

        curr = head
        while l1 != None or l2 != None:
            if l1 == None:
                curr.next = l2
                curr = curr.next
                l2 = l2.next
            elif l2 == None:
                curr.next = l1
                curr = curr.next
                l1 = l1.next
            elif l1.val <= l2.val:
                curr.next = l1
                curr = curr.next
                l1 = l1.next
            else:
                curr.next = l2
                curr = curr.next
                l2 = l2.next

        return head