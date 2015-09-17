#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > pathSum(TreeNode* root, int sum) {
    vector<vector<int> > result;
    if(!root)
        return result;
    if(!root->left && !root->right) {
        if(root->val == sum) {
            vector<int> path;
            path.push_back(sum);
            result.push_back(path);
        }
        return result;
    }
    if(root->right) {
        vector<vector<int> > right = pathSum(root->right, sum - root->val);
        for (int i = 0; i < right.size(); ++i)
        {
            right[i].insert(right[i].begin(), root->val);
            result.push_back(right[i]);
        }
    }
    if(root->left) {
        vector<vector<int> > left = pathSum(root->left, sum - root->val);
        for (int i = 0; i < left.size(); ++i)
        {
            left[i].insert(left[i].begin(), root->val);
            result.push_back(left[i]);
        }
    }
    return result;
}

int main() {
    return 0;
}