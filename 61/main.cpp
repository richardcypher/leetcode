#include <iostream>

using namespace std;
struct ListNode {
    int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if(!head)
        return NULL;
    ListNode* hd = head, *hd1 = head,* hd2, *result;
    ListNode * tmp = head;
    int length = 0;
    while(tmp) {
        length ++;
        tmp = tmp->next;
    }
    k = k % length;
    if(k == 0)
        return head;
    int i = 0;
    while(i < k && hd) {
        hd = hd->next;
        i++;
    }
    while(hd) {
        hd1 = hd1->next;
        hd = hd->next;
    }
    result = hd1;
    hd2 = hd1;
    while(hd1->next)
        hd1 = hd1->next;
    while(head != hd2) {
        hd1->next = new ListNode(head->val);
        head = head->next;
        hd1 = hd1->next;
    }
    return result;
}
int main() {
    ListNode * n1,*n2,*n3,*n4,*n5;
    n5 = new ListNode(5);
    n4 = new ListNode(4);
    n3 = new ListNode(3);
    n2 = new ListNode(2);
    n1 = new ListNode(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    ListNode * n = rotateRight(n1,0);
    while(n) {
        cout<<n->val<<'\t';
        n = n->next;
    }
    cout<<endl;
}