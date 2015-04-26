#include <iostream>

using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 ListNode *swapPairs(ListNode *head) {
    if(!head)
        return NULL;
    else if(!head->next)
        return head;
    ListNode* tmp,*lasthead;
    ListNode* result = head->next;
    lasthead = NULL;
    while(head) {
        if(!head->next)
            break;
        tmp = head->next;
        head->next = tmp->next;
        tmp->next = head;
        if(lasthead) 
            lasthead->next = tmp;
        lasthead = head;
        head = head->next;
    }
    return result;
 }
int main() {
    ListNode* a = new ListNode(1),
    *b = new ListNode(2),
    *c = new ListNode(3),
    *d = new ListNode(4);
    a->next = b;
    b->next = c;
    // c->next = d;
    ListNode* head = swapPairs(a);
    while(head) {
        cout<<head->val<<'\t';
        head = head->next;
    }
    cout<<endl;
    return 0;
}