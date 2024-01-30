/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = NULL;
        ListNode* next_node = head;
        ListNode* temp_node;
                
        while(next_node != NULL) {
            temp_node = next_node->next;
            next_node->next = curr;
            curr = next_node;
            next_node = temp_node;
        }
        return curr;
    }
};
