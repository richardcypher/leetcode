/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月21日 星期三 16时05分07秒
    首先不断将左节点压入栈中，当左节点为空时，弹出并访问当前节点，
    接下来指针指向当前节点的右节点，如果右节点为空，则指针指向当前节点的
    父节点
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    stack<TreeNode*> st;
    TreeNode* tn;
    BSTIterator(TreeNode *root) {
        tn = root;
    }

    bool hasNext() {
        return (tn || !st.empty());
    }

    int next() {
        while(tn) {
            st.push(tn);
            tn = tn->left;
        }
        tn = st.top();
        st.pop();
        int val = tn->val;
        tn = tn->right;
        return val;
    }
};
