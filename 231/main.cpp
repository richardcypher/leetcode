/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月13日 星期五 18时24分29秒
 ************************************************************************/

#include<iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    if(n == 0 || n == -2147483648)
        return false;
    n = n & (n - 1);
    return n == 0;
}
int main() {
    
}
