/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月13日 星期五 18时54分16秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || !p || !q)
        return NULL;
    if((root->val >= p->val && root->val <= q->val) || (root->val >= q->val && root->val <= p->val))
        return root;
    if(root->val >= p->val)
        return lowestCommonAncestor(root->left, p, q);
    else
        return lowestCommonAncestor(root->right, p, q);
}

int main(){}
