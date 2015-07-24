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
}

 int main () {
    return 0;
 }