/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月19日 星期四 11时23分32秒
 ************************************************************************/

#include<iostream>
using namespace std;

bool isUgly(int num) {
    if(num == 1)
        return true;
    if(num == 0)
        return false;
    while(num % 2 == 0)
        num /= 2;
    if(num == 1)
        return true;
    while(num % 3 == 0)
        num/= 3;
    if(num == 1)
        return true;
    while(num % 5 == 0)
        num /= 5;
    if(num == 1)
        return true;
    return false;
}

int main() {
    
}
