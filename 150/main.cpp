/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月15日 星期四 18时38分45秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
#include<sstream>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    int result = 0;
    for(int i = 0; i < tokens.size(); i++) {
        int val1, val2;
        if(tokens[i] == "+"){
                val1 = st.top();
                st.pop();
                val2 = st.top();
                st.pop();
                st.push(val1 + val2);
        }
        else if(tokens[i] == "-") {
                val1 = st.top();
                st.pop();
                val2 = st.top();
                st.pop();
                st.push(val2 - val1);
        }
        else if(tokens[i] == "*"){
                val1 = st.top();
                st.pop();
                val2 = st.top();
                st.pop();
                st.push(val2 * val1);
        }
        else if(tokens[i] == "/") {
                val1 = st.top();
                st.pop();
                val2 = st.top();
                st.pop();
                st.push(val2 / val1);
        }
        else {
            int val;
            stringstream ss(tokens[i]);
            ss>>val;
            st.push(val);
        }
    }
    return st.top();
}
int main() {
    return 0;
}
