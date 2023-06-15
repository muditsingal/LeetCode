/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int min_diff = 999999;
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> node_stk;
        TreeNode* curr_node = nullptr;
        TreeNode* prev_node = nullptr;
        curr_node = root;
        int curr_diff;

        while(curr_node != NULL || !node_stk.empty())
        {
            if(curr_node != NULL)
            {
                node_stk.push(curr_node);
                curr_node = curr_node->left;
            }
            else
            {
                curr_node = node_stk.top();
                node_stk.pop();
                if (prev_node != NULL)
                {
                    curr_diff = curr_node->val - prev_node->val;
                    if (curr_diff < min_diff)
                        min_diff = curr_diff;
                }
                prev_node = curr_node;
                curr_node = curr_node->right;
            }
        }
        return min_diff;
    }
};
