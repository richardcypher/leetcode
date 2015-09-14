#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

TreeNode* convertHelper(ListNode* head, int length) {
    if(length == 1) {
        TreeNode* node = new TreeNode(head->val);
        return node;
    }
    else if(length == 0)
        return NULL;
    ListNode* it = head;
    for (int i = 0; i < (length - 1) / 2; ++i)
    {
        it = it->next;
    }
    TreeNode* root = new TreeNode(it->val);
    TreeNode* left = convertHelper(head, (length - 1) / 2);
    TreeNode* right = convertHelper(it->next, length / 2);
    root->left = left;
    root->right = right;
    return root;
}

 TreeNode* sortedListToBST(ListNode* head) {
    if(!head)
        return NULL;
    int length = 0;
    ListNode* it = head;
    while(it) {
        length++;
        it = it->next;
    }
    return convertHelper(head, length);
}

int main() {
    return 0;
}