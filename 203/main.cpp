/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月26日 星期一 20时35分21秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val) {
    if(!head)
        return NULL;
    while(head->val == val) {
        if(!head->next)
            return NULL;
        head = head->next;
    }
    ListNode* node = head;
    while(node->next) {
        if(node->next->val == val) {
            node->next = node->next->next;
        }
        else
            node = node->next;
    }
    return head;
}

int main() {
    return 0;
}
