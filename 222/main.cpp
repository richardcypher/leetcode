/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月09日 星期一 16时05分44秒
    如果是完美二叉树，则节点数为2^h-1,否则递归计算左右节点数
 ************************************************************************/

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int countNodes(TreeNode* root) {
    TreeNode* left = root, *right = root;
    int dep = 0;
    while(left&&right) {
        left = left->left;
        right = right->right;
        dep++;
    }
    if(!left && !right)
        return (1<<dep) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countNodes1(TreeNode* root) {
    if(!root)
        return 0;
    int count = 1;
    int left = 0, right = 0;
    if(root->left) {
        left = countNodes(root->left);
        right = countNodes(root->right);
    }
    count += left + right;
    return count;
}

int main() {
    return 0;
}
