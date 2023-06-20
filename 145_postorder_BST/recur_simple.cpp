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
    vector<int> node_list;
    void postorder_trav(TreeNode* curr)
    {
        if (curr == NULL)
            return;
        
        postorder_trav(curr->left);
        postorder_trav(curr->right);
        node_list.push_back(curr->val);

    }
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL)
            return node_list;
            
        postorder_trav(root);
        return node_list;
    }
};
