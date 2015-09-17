#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode* root, int sum) {
    if(!root)
        return false;
    if(!root->left && !root->right)
        return root->val == sum;
    else if(!root->left)
        return hasPathSum(root->right, sum - root->val);
    else if(!root->right)
        return hasPathSum(root->left, sum - root->val);
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

int main() {
    return 0;
}
