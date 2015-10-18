/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月18日 星期日 10时02分00秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class minStack {
public:
    vector<int> num;
    vector<int> minIndex;
    void push(int x) {
        num.push_back(x);
        if(minIndex.empty()) {
            minIndex.push_back(num.size() - 1);
        }
        else if(x <= num[minIndex[minIndex.size() - 1]])
            minIndex.push_back(num.size() - 1);
    }

    void pop() {
        if(minIndex[minIndex.size() - 1] == num.size() - 1)
            minIndex.pop_back();
        num.pop_back();
    }

    int top() {
        return num[num.size() - 1];
    }

    int getMin() {
        return num[minIndex[minIndex.size() - 1]];   
    }
};
