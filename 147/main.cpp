/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月14日 星期三 19时12分43秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* head) {
    if(!head || !head->next)
        return head;
    ListNode* it = head, *next = NULL, *it1 = NULL;
    while(it->next) {
        it1 = head;
        while(it1 != it->next) {
            if(it1->val <= it->next->val) {
                it1 = it1->next;
                if(it1 == it->next) {
                    it = it->next;
                    break;
                }
            }
            else {
                int val = it->next->val;
                ListNode* tmp = it->next;
                tmp->val = it1->val;
                it1->val = val;
                it->next = it->next->next;
                tmp->next = it1->next;
                it1->next = tmp;
                break;
            }
        }
    }
    return head;
}
int main() {
    ListNode* a = new ListNode(4),*b = new ListNode(2),*c = new ListNode(1),*d = new ListNode(3);
    a->next = b;
    b->next = c;
    c->next = d;
    ListNode*head = insertionSortList(a);
    ListNode* itt = head;
    while(itt) {
        cout<<itt->val<<'\t';
        itt = itt->next;
    }
    cout<<endl;
    return 0;
}
