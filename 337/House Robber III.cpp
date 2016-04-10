/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        int l1 = root->val, l2 = rob(root->left) + rob(root->right);
        if(root->left)
            l1 += rob(root->left->left) + rob(root->left->right);
        if(root->right)
            l1 += rob(root->right->left) + rob(root->right->right);
        return l1 > l2 ? l1 : l2;
    }
};
