/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月20日 星期二 21时17分12秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int titleToNumber(string s) {
    int result = 0;
    for(int i = 0; i < s.length(); i++) {
        result = result * 26 + (s[i] - 'A' + 1);
    }
    return result;
}

int main() {
    return 0;
}
