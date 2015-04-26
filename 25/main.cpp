#include <iostream>

using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
ListNode *reverseKGroup(ListNode *head, int k) {
    if(!head)
        return NULL;
    if(k <= 1)
        return head;
    ListNode* result = NULL, *lasthead = NULL, *nexthead = NULL;
    while(head) {
        ListNode* grpend = head;
        bool full = true;
        for (int i = 0; i < k - 1; ++i)
        {
            grpend = grpend->next;
            if(!grpend) {//k group end
                if(!result)
                    result = head;
                else
                    lasthead->next = head;
                full = false;
                break;
            }
        }
        if(!full)
            break;
        if(!result)
            result = grpend;
        nexthead = grpend->next;
        //swap k nodes
        ListNode* grphead = head, *tmp = NULL, *lasttail = NULL;
        for (int i = 0; i < k; ++i)
        {
            tmp = grphead->next;
            grphead->next = lasttail;
            lasttail = grphead;
            grphead = tmp;
        }
        if(lasthead)
            lasthead->next = grpend;
        lasthead = head;
        head = nexthead;
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
    c->next = d;
    ListNode* head = reverseKGroup(a, 3);
    while(head) {
        cout<<head->val<<'\t';
        head = head->next;
    }
    cout<<endl;
    return 0;
}