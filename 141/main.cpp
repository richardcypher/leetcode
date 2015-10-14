/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月14日 星期三 16时05分28秒
 ************************************************************************/

#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if(!head || !head->next)
        return false;
    ListNode* fast = head->next->next, *slow = head->next;
    while(fast != slow) {
        if(!fast || !fast->next || !slow)
            return false;
        fast = fast->next->next;
        slow = slow->next;
    }
    return true;
}

int main() {
    return 0;
}
