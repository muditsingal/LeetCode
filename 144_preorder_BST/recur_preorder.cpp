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
    vector<int> res;
    void preorder_trav(TreeNode* curr)
    {
        if (curr == NULL)
            return;

        res.push_back(curr->val);
        preorder_trav(curr->left);
        preorder_trav(curr->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL)
            return res;

        preorder_trav(root);
        return res;
    }
};
