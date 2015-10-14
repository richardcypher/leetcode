/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月14日 星期三 18时29分58秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    if(!root)
        return result;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        result.push_back(node->val);
        if(node->right)
            st.push(node->right);
        if(node->left)
            st.push(node->left);
    }
    return result;
}
int main() {
    return 0;
}
