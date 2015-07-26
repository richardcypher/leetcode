#include <iostream>
#include <vector>
#include <stack>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    if(!root)
        return result;
    stack<TreeNode*> st;
    TreeNode* tn = root;
    while(tn || !st.empty()) {
        if(tn) {
            st.push(tn);
            tn = tn->left;
        }
        else {
            tn = st.top();
            result.push_back(tn->val);
            st.pop();
            tn = tn->right;
        }
    }
    return result;
}

int main() {

}