#include <iostream>
#include <queue>

using namespace std;

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
    if(!root)
        return;
    queue<TreeLinkNode*> q;
    int num = 0, total = 1;
    q.push(root);
    while(!q.empty()){
        TreeLinkNode* node = q.front();
        q.pop();
        if(node->left) {
            q.push(node->left);
            q.push(node->right);
        }
        num++;
        if(num == total) {
            num = 0;
            total *= 2;
            node->next = NULL;
        }
        else {
            node->next = q.front();
        }
    }
}

void connect2(TreeLinkNode* left, TreeLinkNode* right) {
    left->next = right;
    if(left->left) {
        connect2(left->left, left->right);
        connect2(right->left, right->right);
        connect2(left->right, right->left);
    }
}

void connect1(TreeLinkNode *root) {
    if(!root || !root->left)
        return ;
    connect2(root->left, root->right);
}

int main() {
    return 0;
}