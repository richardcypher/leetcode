#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymm(TreeNode* left, TreeNode* right) {
    if(!left && !right)
        return true;
    if((!left && right) || (left && !right))
        return false;
    if(left->val != right->val)
        return false;
    return isSymm(left->left, right->right) && isSymm(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if(!root)
        return true;
    return isSymm(root->left, root->right);
}

int main() {
    return 0;
}