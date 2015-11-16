#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool findPath(TreeNode* root, TreeNode* node, vector<TreeNode*> &paths) {
    paths.push_back(root);
    if(root == node) {
        return true;
    }
    if(root->left) {
        if(findPath(root->left, node, paths))
            return true;
    }
    if(root->right) {
         if(findPath(root->right, node, paths))
             return true;
    }
    paths.pop_back();
    return false;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> lpath, rpath;
    findPath(root, p, lpath);
    findPath(root, q, rpath);
    int i = 0;
    while(i < lpath.size() && i < rpath.size()) {
        if(lpath[i] != rpath[i])
            return lpath[i - 1];
        i++;
    }
    if(i == lpath.size())
        return lpath[i - 1];
    if(i == rpath.size())
        return rpath[i - 1];
}

int main() {
    return 0;
}
