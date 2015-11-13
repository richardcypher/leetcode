/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月13日 星期五 19时02分02秒
    方法1：利用两个指针将链表后半段翻转，然后对比
    方法2：递归，定义一个tmp，每次先判断p->next和tmp是否相等，然后移动tmp
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool check(ListNode*p, ListNode** tmp) {
    if(!p)
        return true;
    bool isPal = check(p->next, tmp) && ((*tmp)->val == p->val);
    *tmp = (*tmp)->next;
    return isPal;
}

bool isPalindrome(ListNode* head) {
    ListNode** tmp = &head;
    return check(head, tmp);
}

int main() {
    
}
