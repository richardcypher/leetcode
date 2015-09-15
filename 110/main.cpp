#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode* root) {
    if(!root)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return 1 + (left > right ? left : right);
}

bool isBalanced(TreeNode* root) {
    if(!root)
        return true;
    int left = height(root->left);
    int right = height(root->right);
    if(left - right <= 1 && left - right >= -1)
        return isBalanced(root->left) && isBalanced(root->right);
    else
        return false;
}

int main() {
    return 0;
}