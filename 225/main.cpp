/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月11日 星期三 16时04分31秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

class Stack {
private:
    queue<int> sts[2];
    int main;
public:
    Stack() {
        main = 0;
    }

    void push(int x) {
        int assist = main;
        main ^= 1;
        sts[main].push(x);
        while(!sts[assist].empty()) {
            sts[main].push(sts[assist].front());
            sts[assist].pop();
        }
    }

    void pop() {
        sts[main].pop();
    }

    int top() {
        return sts[main].front();
    }

    bool empty() {
        return sts[main].empty();
    }
};

int main() {
    Stack s;
    s.push(0);
}
