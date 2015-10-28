/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月28日 星期三 10时54分51秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode *head) {
    if(!head)
        return NULL;
    ListNode* node = head, *last = NULL, *next = NULL;
    while(node->next) {
        next = node->next;
        node->next = last;
        last = node;
        node = next;
    }
    node->next = last;
    return node;
}
int main() {
    return 0;
}
