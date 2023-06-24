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
    int sum_l_leaves = 0;
    void traversal(TreeNode* curr)
    {
        if(curr == NULL)
            return;

        if(curr->left != NULL)
        {
            if(curr->left->left == NULL && curr->left->right == NULL)
                sum_l_leaves += curr->left->val;
        }

        traversal(curr->left);
        traversal(curr->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        traversal(root);
        return sum_l_leaves;
    }
};
