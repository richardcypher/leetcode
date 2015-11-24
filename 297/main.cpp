#include<iostream>
#include<queue>
#include<sstream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
public:
    string num2str(int n) {
        stringstream ss;
        ss<<n;
        return ss.str();
    }

    int str2num(string str) {
        stringstream ss(str);
        int n;
        ss>>n;
        return n;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "#";
        queue<TreeNode*> q;
        q.push(root);
        string str = num2str(root->val) + " ";
        TreeNode* node;
        while(!q.empty()) {
            node = q.front();
            q.pop();
            if(node->left) {
                q.push(node->left);
                str += num2str(node->left->val) + " ";
            }
            else {
                str += "# ";
            }
            if(node->right) {
                q.push(node->right);
                str += num2str(node->right->val) + " ";
            }
            else {
                str += "# ";
            }
        }
        str.erase(str.find_last_not_of(" ") + 1);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#")
            return NULL;
        stringstream ss(data);
        string str;
        TreeNode* root, *node1, * node;
        queue<TreeNode*> q;
        ss>>str;
        root = new TreeNode(str2num(str));
        q.push(root);
        bool left = true;
        while(ss>>str) {
            if(left) {
                node = q.front();
                q.pop();
                left = false;
                node1 = NULL;
                if(str != "#") {
                    node1 = new TreeNode(str2num(str));
                    q.push(node1);
                }
                node->left = node1;
            }
            else {
                left = true;
                node1 = NULL;
                if(str != "#") {
                    node1 = new TreeNode(str2num(str));
                    q.push(node1);
                }
                node->right = node1;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(){
    Codec c;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    string s = c.serialize(root);
    cout<<s<<endl;
    TreeNode* n = c.deserialize(s);
    cout<<c.serialize(n)<<endl;
}