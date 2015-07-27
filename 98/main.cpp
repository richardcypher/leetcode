#include <iostream>
#include <stack>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

bool isValidBST(TreeNode* root) {
    if(!root)
        return true;
    stack<TreeNode*> st;
    int lastval;
    bool first = true;
    while(root || !st.empty()) {
        if(root) {
            st.push(root);
            root = root->left;
        }
        else {
            root = st.top();
            if(first) {
                lastval = root->val;
                first = false;
            }
            else {
                if(lastval >= root->val)
                    return false;
                lastval = root->val;
            }
            st.pop();
            root = root->right;
        }
    }
    return true;
}

int main() {
    return 0;
}