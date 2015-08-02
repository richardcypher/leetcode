#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildHelper(vector<int>& inorder, vector<int>& postorder, int i1, int j1, int i2, int j2) {
    if (i1 > j1 || i2 > j2 || i1 < 0 || i2 < 0 || j1 > inorder.size() - 1 || j2 > postorder.size() - 1)
        return NULL;
    TreeNode* root = new TreeNode(postorder[j2]);
    int index = i1;
    for (; index <= j1; ++index)
    {
        if(inorder[index] == postorder[j2])
            break;
    }
    TreeNode* left = buildHelper(inorder, postorder, i1, index - 1, i2, i2 + index - i1 - 1);
    TreeNode* right = buildHelper(inorder, postorder, index + 1, j1, i2 + index - i1, j2 - 1);
    root->left = left;
    root->right = right;
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return buildHelper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
}

int main() {
    return 0;
}