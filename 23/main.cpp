#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
ListNode* merge2Lists(ListNode* list1, ListNode* list2) {
    if(!list1)
        return list2;
    if(!list2)
        return list1;
    ListNode* head = new ListNode(list1->val < list2->val ? list1->val:list2->val);
    ListNode* it = head;
    if(list1->val < list2->val)
        list1 = list1->next;
    else
        list2 = list2->next;
    while(list1 && list2) {
        it->next = new ListNode(list1->val < list2->val ? list1->val:list2->val);
        it = it->next;
        if(list1->val < list2->val)
            list1 = list1->next;
        else
            list2 = list2->next;
    }
    if(list1)
        it->next = list1;
    else
        it->next = list2;
    return head;
}

 ListNode *mergeKLists(vector<ListNode *> &lists) {
    if(lists.size() == 0)
        return NULL;
    else if(lists.size() == 1)
        return lists[0];
    while(lists.size() != 1) {
        ListNode* head1 = lists[0];
        ListNode *head2 = lists.empty() ? NULL : lists[1];
        ListNode * mhead = merge2Lists(head1, head2);
        lists.push_back(mhead);
        lists.erase(lists.begin());
        if(lists.size() > 1)
            lists.erase(lists.begin());
    }
    return lists[0];
}

int main() {
    ListNode* a = new ListNode(1),
        *b = new ListNode(2),
        *c = new ListNode(3),
        *d = new ListNode(4),
        *e = new ListNode(5);
    a->next = d;
    b->next = e;
    std::vector<ListNode*> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    ListNode* head = mergeKLists(v);
    while(head) {
        cout<<head->val<<'\t';
        head = head->next;
    }
    cout<<endl;
    return 0;
}