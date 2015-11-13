/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月13日 星期五 17时21分41秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool traversal(TreeNode* root, int k, int& i, int &result) {
    if(!root)
        return false;
    if(root->left) {
        if(traversal(root->left, k, i , result))
            return true;
    }
    i++;
    if(i == k) {
        result = root->val;
        return true;
    }
    if(root->right) {
        if(traversal(root->right, k, i, result))
            return true;
    }
    return false;
}

int kthSmallest(TreeNode* root, int k) {
    int i = 0, result;
    traversal(root, k, i, result);
    return result;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(8);
    cout<<kthSmallest(root, 2)<<endl;
}
