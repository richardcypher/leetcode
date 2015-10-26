/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月26日 星期一 19时39分30秒
 ************************************************************************/

#include<iostream>
using namespace std;

int rangeBitwiseAnd(int m, int n) {
    if((m ^ n) > m)
        return 0;
    if(m == n)
        return m;
    int diff = n - m, cnt = 0;
    while(diff > 0) {
        cnt++;
        diff >>= 1;
    }
    return ((m & n) >> cnt) << cnt;
}

int main() {
    return 0;
}
