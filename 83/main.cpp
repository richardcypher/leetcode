#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* deleteDuplicates(ListNode* head) {
    if(!head || !head->next)
        return head;
    while(head->next && head->val == head->next->val)
        head = head->next;
    ListNode* result = new ListNode(head->val);
    ListNode* tmp = result;
    head = head->next;
    while(head) {
        tmp->next = new ListNode(head->val);
        tmp = tmp->next;
        while(head->next && head->next->val == head->val)
            head = head->next;
        head = head->next;
    }
    return result;
}
int main() {
    ListNode*a = new ListNode(1), *b = new ListNode(2), *c = new ListNode(2),*d = new ListNode(3), *e = new ListNode(4), *f = new ListNode(4),
    *g = new ListNode(5);
    a->next = b;
    b->next = c;
    c->next = d;
    // d->next = e;
    // e->next = f;
    // f->next = g;
    ListNode* ln = deleteDuplicates(a);
    while(ln) {
        cout<<ln->val<<'\t';
        ln = ln->next;
    }
    cout<<endl;
    return 0;
}