/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月19日 星期四 10时40分36秒
 ************************************************************************/

#include<iostream>
using namespace std;

int addDigits(int num) {
    int n;
    while(num / 10 >= 1) {
        n = num;
        num = 0;
        while(n / 10 > 0) {
            num += n % 10;
            n /= 10;
        }
        num += n;
    }
    return num;
}

int main() {
    
}
