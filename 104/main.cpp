#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return 1;
    int leftdep = maxDepth(root->left);
    int rightdep = maxDepth(root->right);
    return 1 + (leftdep > rightdep ? leftdep : rightdep);
}

int main() {
    return 0;
}