#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrderBottom(TreeNode* root) {
    vector<vector<int> > traversal;
    if(!root)
        return traversal;
    queue<TreeNode*> q;
    stack<vector<int> >st;
    q.push(root);
    TreeNode* node = NULL;
    vector<int> level;
    while(!q.empty()) {
        TreeNode* tnode = q.front();
        if(node && node == tnode) {
            st.push(level);
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
    st.push(level);
    while(!st.empty()) {
        traversal.push_back(st.top());
        st.pop();
    }
    return traversal;
}

int main() {
    return 0;
}