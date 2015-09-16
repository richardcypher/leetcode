#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode* root) {
    if(!root)
        return 0;
    if(!root->left)
        return 1 + minDepth(root->right);
    if(!root->right)
        return 1 + minDepth(root->left);
    int minleft = minDepth(root->left), minright = minDepth(root->right);
    return 1 + (minleft < minright ? minleft  : minright);
}

int main() {

    return 0;
}