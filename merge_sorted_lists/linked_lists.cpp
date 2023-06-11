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

#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res;
        ListNode* curr;
        ListNode* l1;
        ListNode* l2;
        l1 = list1;
        l2 = list2;
        if (l1 == NULL)
        {
            res = l2;
            return res;
        }
        else if (l2 == NULL)
        {
            res = l1;
            return res;
        }
        if (l1->val <= l2->val)
        {
            res = new ListNode(l1->val);
            curr = res;
            l1 = l1->next;
        }
        else
        {
            res = new ListNode(l2->val);
            curr = res;
            l2 = l2->next;
        }
        while (l1 != NULL || l2 != NULL)
        {
            if (l1 == NULL)
            {
                curr->next = l2;
                curr = curr->next;
                l2 = l2->next;
            }
            else if (l2 == NULL)
            {
                curr->next = l1;
                curr = curr->next;
                l1 = l1->next;
            }
            else if (l1->val <= l2->val)
            {
                curr->next = l1;
                curr = curr->next;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                curr = curr->next;
                l2 = l2->next;
            }
        }
        delete(l1);
        delete(l2);

        return res;
    }
};
