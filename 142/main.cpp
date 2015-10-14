/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月14日 星期三 16时40分36秒
 ************************************************************************/

#include<iostream>
using namespace std;

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    if(!head || !head->next)
        return NULL;
    ListNode* fast = head->next->next, *slow = head->next;
    while(fast != slow) {
        if(!fast || !fast->next || !slow)
            return NULL;
        fast = fast->next->next;
        slow = slow->next;
    }
    for(fast = head; fast != slow; fast = fast->next, slow = slow->next)
        ;
    return fast;
}

int main() {
    return 0;
}
