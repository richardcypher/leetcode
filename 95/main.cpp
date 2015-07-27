#include <iostream>
#include <vector>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 vector<TreeNode*> generateTrees(int n) {
    if(n == 0) {
        std::vector<TreeNode*> v;
        v.push_back(NULL);
        return v;
    }
    vector<TreeNode*> **t = new vector<TreeNode*>*[n];
    for (int i = 0; i < n; ++i)
    {
        t[i] = new vector<TreeNode*>[n];
    }
    for (int i = 0; i < n; ++i)
    {
        TreeNode* node = new TreeNode(i + 1);
        t[i][i].push_back(node);
    }
    for (int s = 1; s <= n - 1; ++s)
    {
        for (int i = 0; i < n - s; ++i)
        {
            int j = i + s;
            for (int ts = 0; ts < t[i + 1][j].size(); ++ts)
            {
                TreeNode* node1 = new TreeNode(i + 1);
                node1->right = t[i + 1][j][ts];
                t[i][j].push_back(node1);
            }
            for (int ts = 0; ts < t[i][j - 1].size(); ++ts)
            {
               TreeNode* node2 = new TreeNode(j + 1);
                node2->left = t[i][j - 1][ts];
                t[i][j].push_back(node2);
            }

            for (int k = i + 1; k < j; ++k)
            {
                for (int tk1 = 0; tk1 < t[i][k - 1].size(); ++tk1)
                {
                    for (int tk2 = 0; tk2 < t[k + 1][j].size(); ++tk2)
                    {
                        TreeNode* nodek = new TreeNode(k + 1);
                        nodek->left = t[i][k - 1][tk1];
                        nodek->right = t[k + 1][j][tk2];
                        t[i][j].push_back(nodek);
                    }
                }
            }
        }
    }
    return t[0][n - 1];
}

void Traversal(TreeNode* root) {
    if(root) cout<<root->val<<'-';
    if(root->left) Traversal(root->left);
    if(root->right) Traversal(root->right);
}

int main() {
    vector<TreeNode*> v = generateTrees(3);
    for (int i = 0; i < v.size(); ++i)
    {
        Traversal(v[i]);
        cout<<endl;
    }
    return 0;
}