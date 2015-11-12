/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月12日 星期四 15时17分10秒
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

int calculate(string s) {
    if(s.empty())
        return 0;
    stack<char> ops;
    stack<int> nums;
    int num = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-') {
            if(s[i] == '+' || s[i] == '-') {
                while(!ops.empty()) {
                    char curr_op = ops.top();
                    ops.pop();
                    int num2 = nums.top();nums.pop();
                    int num1 = nums.top();nums.pop();
                    if(curr_op == '+') {
                        nums.push(num1 + num2);
                    }
                    else if(curr_op == '-') {
                        nums.push(num1 - num2);
                    }
                }
            }
            ops.push(s[i]);
        }
        else if(s[i] == ' ') {}
        else {
            num = num * 10 + (s[i] - '0');
            if(i == s.length() - 1 || s[i + 1] < '0' || s[i + 1] > '9') {
                nums.push(num);
                num = 0;
                if(!ops.empty()) {
                    char curr_op = ops.top();
                    if(curr_op == '/') {
                        ops.pop();
                        int num2 = nums.top();nums.pop();
                        int num1 = nums.top();nums.pop();
                        nums.push(num1 / num2);
                    }
                    else if(curr_op == '*') {
                        ops.pop();
                        int num2 = nums.top();nums.pop();
                        int num1 = nums.top();nums.pop();
                        nums.push(num1 * num2);
                    }
                }
            }
        }
    }
    if(!ops.empty()) {
        char curr_op = ops.top();
        ops.pop();
        int num2 = nums.top();nums.pop();
        int num1 = nums.top();nums.pop();
        if(curr_op == '+') {
            nums.push(num1 + num2);
        }
        else if(curr_op == '-') {
            nums.push(num1 - num2);
        }
    }
    return nums.top();
}

int main(){
    cout<<calculate("3+2*2")<<endl;
}
