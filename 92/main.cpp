#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode* before = NULL, *lastnode = NULL, * start = head;
    if(m != 1) {
        before = head;
        for (int i = 2; i < m; ++i)
            before = before->next;
        start = before->next;
    }
    ListNode* it = start;
    for (int i = m; i <= n; ++i)
    {
        ListNode* tmp = it->next;
        it->next = lastnode;
        lastnode = it;
        it = tmp;
    }
    if(before)
        before->next = lastnode;
    start->next = it;
    if(before)
        return head;
    else
        return lastnode;
}

 int main () {
    ListNode* l1 = new ListNode(1), *l2 = new ListNode(2), * l3 = new ListNode(3), *l4 = new ListNode(4),*l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    ListNode * l = reverseBetween(l1, 2, 5);
    while(l) {
        cout<<l->val<<'\t';
        l = l->next;
    }
    cout<<endl;
    return 0;
 }