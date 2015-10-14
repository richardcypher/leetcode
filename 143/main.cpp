/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月14日 星期三 18时39分42秒
 ************************************************************************/

#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void reorderList1(ListNode* head){
    ListNode* reverse = NULL;
    int length = 0;
    ListNode* it = head, *last = NULL;
    while(it) {
        reverse = new ListNode(it->val);
        reverse->next = last;
        last = reverse;
        it = it->next;
        length++;
    }
    it = head;
    ListNode* next1 = NULL, *next2 = NULL;
    for(int i = 0; i < length/2; i++) {
        next1 = it->next;
        if(length % 2 == 0 && i == length/2 - 1)
            next1 = NULL;
        else if(length % 2 != 0 && i == length/2 - 1)
            next1->next = NULL;
        next2 = reverse->next;
        it->next = reverse;
        reverse->next = next1;
        it = next1;
        reverse = next2;
    }
}

int main() {
    return 0;
}
