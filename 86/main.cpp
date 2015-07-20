#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 ListNode* partition(ListNode* head, int x) {
    if(!head || !head->next)
        return head;
    ListNode* head1 = NULL,*head2 = NULL;
    ListNode* it1 = NULL, * it2 = NULL;
    while(head) {
        if(head->val < x) {
            if(!head1) {
                head1 = new ListNode(head->val);
                it1 = head1;
            }
            else {
                head1->next = new ListNode(head->val);
                head1 = head1->next;
            }
        }
        else {
            if(!head2) {
                head2 = new ListNode(head->val);
                it2 = head2;
            }
            else {
                head2->next = new ListNode(head->val);
                head2 = head2->next;
            }
        }
        head = head->next;
    }
    if(!it1)
        return it2;
    head1->next = it2;
    return it1;
}

int main() {
    ListNode*a = new ListNode(1), *b = new ListNode(1), *c = new ListNode(2),*d = new ListNode(1), *e = new ListNode(4), *f = new ListNode(4),
    *g = new ListNode(5);
    a->next = b;
    // b->next = c;
    // c->next = d;
    // d->next = e;
    // e->next = f;
    // f->next = g;
    ListNode* ln = partition(a, 2);
    cout<<endl;
    while(ln) {
        cout<<ln->val<<'\t';
        ln = ln->next;
    }
    cout<<endl;
    return 0;
}