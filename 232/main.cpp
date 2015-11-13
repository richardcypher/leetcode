/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月13日 星期五 18时33分31秒
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

class Queue {
private:
    stack<int> q[2];
public:
    // Push element x to the back of queue.
    void push(int x) {
        while(!q[0].empty()) {
            q[1].push(q[0].top());
            q[0].pop();
        }
        q[0].push(x);
        while(!q[1].empty()) {
            q[0].push(q[1].top());
            q[1].pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        q[0].pop();
    }

    // Get the front element.
    int peek(void) {
        return q[0].top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return q[0].empty();
    }
};
