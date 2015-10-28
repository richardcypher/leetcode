/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月26日 星期一 20时16分30秒
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;

bool isHappy(int n) {
    map<int, bool> mp;
    int tmp;
    while(n != 1) {
        tmp = n;
        n = 0;
        while(tmp > 0) {
            n += (tmp % 10) * (tmp % 10);
            tmp /= 10;
        }
        if(mp.find(n) != mp.end())
            return false;
        mp[n] = true;
    }
    return true;
}

int main() {
    cout<<isHappy(7)<<endl;
    return 0;
}
