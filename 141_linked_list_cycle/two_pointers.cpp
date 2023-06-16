/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;
            
        else if (head->next == NULL)
            return false;

        bool hasCycle = false;
        ListNode* ptr;
        ListNode* ptr_skip;
        ptr = head;
        ptr_skip = head->next;

        while (!hasCycle && ptr_skip != NULL)
        {
            if(ptr == ptr_skip)
                hasCycle = true;
            ptr = ptr->next;
            if (ptr_skip->next == NULL)
                break;
            ptr_skip = ptr_skip->next->next;
        }

        return hasCycle;  
    }
};
