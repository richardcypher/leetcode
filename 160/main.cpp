/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月18日 星期日 11时11分27秒
    >两个指针对应pA和pB,分别遍历各自的链表,当pA到达链表末尾的时候令pA=headB;
    同样,当pB到达链表末尾的时候令pB=headA,这样,当进行到第二个循环的时候,两个指针会同时到达
    链表末尾,这时判断两个链表的末尾是否相等,如果相等,则
    pA=pB的时候,pA就是两个链表的交点;否则,两个链表没有交点.
************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getINtersectionNode(ListNode *headA, ListNode* headB) {
    if(!headA || !headB) {
        return NULL;
    }
    int lengthA = 0, lengthB = 0;
    ListNode* itA = headA, * itB = headB;
    while(itA) {
        lengthA++;
        itA = itA->next;
    }
    while(itB) {
        lengthB++;
        itB = itB->next;
    }
    itA = headA;
    itB = headB;
    if(lengthA > lengthB) {
        for(int i = 0; i < lengthA - lengthB; i++)
            itA = itA->next;
    }
    else if(lengthA < lengthB) {
        for(int i = 0; i < lengthB - lengthA; i++)
            itB = itB->next;
    }
    while(itA && itB) {
        if(itA == itB)
            return itA;
        itA = itA->next;
        itB = itB->next;
    }
    return NULL;
}

int main() {
    return 0;
}
