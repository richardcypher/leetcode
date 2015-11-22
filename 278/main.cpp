/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月22日 星期日 22时37分53秒
 ************************************************************************/

#include<iostream>
using namespace std;

bool isBadVersion(int version){}

int firstBadVersion(int n) {
    int low = 1, high = n, mid;
    while(low < high) {
        mid = low + (high - low) / 2;//(low + high) / 2 may cause overflow!!!!!
        if(isBadVersion(mid)){
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    return high;
}

int main(){}
