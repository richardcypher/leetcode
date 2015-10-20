/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月20日 星期二 21时26分53秒
    > n/5表示在不大于n的数中5的倍数贡献1个5,n/25表示在不大于n的数中25的倍数贡献1个5,
    以此类推,所有数相加就是5的个数,即末尾0的个数.
 ************************************************************************/

#include<iostream>
using namespace std;

int trailingZeroes(int n) {
    int num = 0;
    while(n >= 5) {
        n /= 5;
        num += n;
    }
    return num;
}

int main() {
    return 0;
}
