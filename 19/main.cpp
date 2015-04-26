#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

ListNode *removeNthFromEnd(ListNode *head, int n) {
    if(!head)
        return NULL;
    ListNode* headcopy = head;
    ListNode* headdupe = head;
    for (int i = 0; i < n; ++i)
    {
        headcopy = headcopy->next;
    }
    if(!headcopy)
    {
        head = headdupe->next;
        return head;
    }
    while(headcopy->next)
    {
        headcopy = headcopy->next;
        head = head->next;
    }
    head->next = head->next->next;
    return headdupe;
}

int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);a->next = b;
    // ListNode* c = new ListNode(3);b->next = c;
    ListNode* r = removeNthFromEnd(a, 2);
    while(r)
    {
        cout<<r->val<<'\t';
        r = r->next;
    }
    cout<<endl;
    return 0;
}