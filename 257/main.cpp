/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月19日 星期四 10时47分01秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string num2str(int num) {
    stringstream ss;
    ss<<num;
    return ss.str();
}

void traversal(TreeNode* root, vector<int>& tmp, vector<string>& result) {
    if(!root)
        return;
    tmp.push_back(root->val);
    if(!root->left && !root->right) {
        string s = "";
        int i = 0;
        for(; i < tmp.size() - 1; i++) {
            s += num2str(tmp[i]) + "->";
        }
        s += num2str(tmp[i]);
        result.push_back(s);
    }
    else {
        traversal(root->left, tmp, result);
        traversal(root->right, tmp, result);
    }
    tmp.pop_back();
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    if(!root)
        return result;
    vector<int> tmp;
    traversal(root, tmp, result);
}

int main() {
    
}
