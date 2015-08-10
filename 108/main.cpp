#include <iostream>
#include <vector>

using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

TreeNode* convertHelper(vector<int>& nums, int low, int high) {
    if(low == high)
    {
        TreeNode* node = new TreeNode(nums[low]);
        return node;
    }
    else if(low > high)
        return NULL;
    int mid = (low + high) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    TreeNode* left = convertHelper(nums, low, mid - 1);
    TreeNode* right = convertHelper(nums, mid + 1, high);
    root->left = left;
    root->right = right;
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(nums.empty())
        return NULL;
    return convertHelper(nums, 0, nums.size() - 1);
}

int main() {
    return 0;
}