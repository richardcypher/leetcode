#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumNumbers(TreeNode* root) {
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return root->val;
    int total = 0;
    if(root->left) {
        root->left->val = root->val * 10 + root->left->val;
        total += sumNumbers(root->left);
    }
    if(root->right) {
        root->right->val = root->val * 10 + root->right->val;
        total += sumNumbers(root->right);
    }
    return total;
}

int main() {
    return 0;
}