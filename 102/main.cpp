#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrder(TreeNode* root) {
    vector<vector<int> > traversal;
    if(!root)
        return traversal;
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* node = NULL;
    vector<int> level;
    while(!q.empty()) {
        TreeNode* tnode = q.front();
        if(node && node == tnode) {
            traversal.push_back(level);
            node = NULL;
            level.clear();
        }
        q.pop();
        level.push_back(tnode->val);
         if(tnode->left) {
            q.push(tnode->left);
            if(!node)
                node = tnode->left;
        }
        if(tnode->right) {
            q.push(tnode->right);
            if(!node)
                node = tnode->right;
        }
    }
    traversal.push_back(level);
    return traversal;
}

int main() {
    return 0;
}