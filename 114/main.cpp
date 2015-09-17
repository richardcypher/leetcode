#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode* root) {
    if(!root)
        return;
    if(!root->left)
    {
        flatten(root->right);
        return;
    }
    if(!root->right)
    {
        flatten(root->left);
        root->right = root->left;
        root->left = NULL;
        return;
    }
    flatten(root->left);
    flatten(root->right);
    TreeNode *tmp1 = root->right,*tmp2 = root->left;
    root->right = root->left;
    root->left = NULL;
    while(tmp2->right)
        tmp2 = tmp2->right;
    tmp2->right = tmp1;
}

int main() {
    return 0;
}