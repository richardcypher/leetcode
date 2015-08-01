#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildHelper(vector<int>& preorder, vector<int>& inorder, int i1, int j1, int i2, int j2) {
    if (i1 > i2 || j1 > j2 || i1 < 0 || j1 < 0 || i2 > preorder.size() - 1 || j2 > inorder.size() - 1)
        return NULL;
    TreeNode * root = new TreeNode(preorder[i1]);
    int index = -1;
    for (int i = j1; i <= j2; ++i)
    {
        if (inorder[i] == preorder[i1])
        {
            index = i;
            break;
        }
    }
    TreeNode* left = buildHelper(preorder, inorder, i1 + 1, j1, index - j1 + i1, index - 1);
    TreeNode* right = buildHelper(preorder, inorder, index - j1 + i1 + 1, index + 1, i2, j2);
    root->left = left;
    root->right = right;
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildHelper(preorder, inorder, 0, 0, preorder.size() - 1, inorder.size() - 1);
}

void levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* tnode = q.front();
        q.pop();
        cout << tnode->val << '\t';
        if (tnode->left) {
            q.push(tnode->left);
        }
        if (tnode->right) {
            q.push(tnode->right);
        }
    }
}

int main() {
    int arr1[] = {-77,24,-74,84,93,28,83,6,95,58,59,66,22,-3,-66,-68,-22,3,-80,-79,-85,17,32,9,-88,-99,14,-60,13,-93,-63,91,82,21,26,-11,-32,-16,-100,-94,-31,-62,-89,49,-9,-8,87,-33,-81,80,0,69,-7,52,67,-5,-65,31,-30,37,-57,27,23,38,-28,7,-82,-42,11,-55,-36,-58,-24,89,56,73,41,18,-87,-70,4,-64,20,-52,-39,79,19,30,65,25,-71,-76,-1,62,-69,98,39,-25,-73,70,88,-17,-20,-75,55,34,57,81,-10,94,48,-35,5,-23,-44,40,-51,-61,-13,-86,63,71,-97,45,43,51,75,33,-34,92,47,-78,85,-26,97,-29,-92,-83,-59,74,96,68,77,16,-4,10,60,64,-21,-2,1,-91,86,46,76,-37,-19,-96,36,-98,29,-72,61,50,15,-95,-40,-43,-53,90,-15,-48,-27,-90,-54,72,-50,-49,-18,78,54,35,-38,99,44,-67,53,-12,-41,2,8,-14,-84,-56,-6,12,-45,42,-47,-46};
    int arr2[] = {93,28,84,83,-74,59,58,66,-66,-3,-79,-80,3,-22,-68,22,-85,-99,14,-88,9,32,17,-60,95,-93,82,21,91,-63,26,13,-16,-32,-11,-100,6,-62,49,-89,-31,87,-8,69,0,80,-7,-81,-65,-5,67,-30,31,52,-33,37,-57,-9,7,-28,-42,-82,38,-55,11,23,-36,27,56,89,73,-24,41,-58,-70,-87,20,-64,-52,4,18,-94,19,30,-76,-1,-71,62,-69,25,-73,-25,70,39,88,98,-20,-17,65,55,-75,79,34,-39,48,94,-23,5,-44,-35,40,-10,-61,-51,-13,81,63,-97,71,-86,57,45,24,-34,85,97,-26,-78,-83,-92,74,-59,96,-29,68,47,77,92,10,-4,16,60,33,-21,1,86,76,46,-37,-91,-2,64,75,51,-19,-96,43,-98,29,61,-72,50,36,-95,-40,-43,15,90,-15,-53,-77,-54,-90,-49,-50,72,-27,35,54,-38,78,-67,44,53,99,-41,-12,-18,8,2,-48,-56,-84,-14,-45,12,42,-6,-46,-47};
    /*int arr1[] = { 1,2,3 };
    int arr2[] = { 2,3,1 };*/
    vector<int> v1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0])), v2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
    TreeNode* root = buildTree(v1, v2);
    levelOrder(root);
    cout << endl;
    return 0;
}