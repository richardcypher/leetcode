/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月15日 星期四 16时46分41秒
 ************************************************************************/

#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge(ListNode*list1, ListNode*list2) {
    if(!list1)
        return list2;
    if(!list2)
        return list1;
    ListNode* head = new ListNode(0);
    ListNode* pre = head;
    ListNode* it1 = list1, *it2 = list2;
    while(it1 && it2) {
        if(it1->val < it2->val)
        {
            head->next = it1;
            head = it1;
            it1 = it1->next;
        }
        else
        {
            head->next = it2;
            head = it2;
            it2 = it2->next;
        }
    }
    if(it1)
        head->next = it1;
    if(it2)
        head->next = it2;
    return pre->next;
}

ListNode* sortList(ListNode* head) {
    if(!head || !head->next) {
        return head;
    }
    ListNode*fast = head,*slow = head;
    while(fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *list1 = head, *list2 = slow->next;
    slow->next = NULL;
    list1 = sortList(list1);
    list2 = sortList(list2);
    return merge(list1, list2);
}

int main() {
    return 0;
}
