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

vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > traversal;
    if(!root)
        return traversal;
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* node = NULL;
    bool right = true;
    vector<int> level;
    stack<int> st;
    while(!q.empty()) {
        TreeNode* tnode = q.front();
        if(node && node == tnode) {
            if(!right) {
                while(!st.empty()) {
                    int tmp = st.top();
                    st.pop();
                    level.push_back(tmp);
                }
                right = true;
            }
            else
                right = false;
            traversal.push_back(level);
            node = NULL;
            level.clear();
        }
        q.pop();
        if(right) {
            level.push_back(tnode->val);
        }
        else {
            st.push(tnode->val);
        }
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
    if(!right) {
        while(!st.empty()) {
            int tmp = st.top();
            st.pop();
            level.push_back(tmp);
        }
    }
    traversal.push_back(level);
    return traversal;
}

int main() {
    return 0;
}