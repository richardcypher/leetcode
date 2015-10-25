/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月25日 星期日 13时33分42秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if(!root)
        return result;
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* node = NULL;
    int target = root->val;
    while(!q.empty()) {
        TreeNode* tnode = q.front();
        q.pop();
        if(node == tnode) {
            result.push_back(target);
            node = NULL;
        }
        target = tnode->val;
        if(tnode->left) {
            if(!node)
                node = tnode->left;
            q.push(tnode->left);
        }
        if(tnode->right) {
            if(!node)
                node = tnode->right;
            q.push(tnode->right);
        }
    }
    result.push_back(target);
    return result;
}

int main() {
    return 0;
}
