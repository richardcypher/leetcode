/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月22日 星期日 15时48分15秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int nthUglyNumber(int n) {
    vector<int>l1, l2, l3;
    l1.push_back(1);
    l2.push_back(1);
    l3.push_back(1);
    int num = 1, i1 = 0, i2 = 0, i3 = 0;
    for(int i = 0; i < n; i++) {
        num = l1[i1];
        if(num > l2[i2])
            num = l2[i2];
        if(num > l3[i3])
            num = l3[i3];
        if(num == l1[i1])
            i1++;
        if(num == l2[i2])
            i2++;
        if(num == l3[i3])
            i3++;
        l1.push_back(num * 2);
        l2.push_back(num * 3);
        l3.push_back(num * 5);
    }
    return num;
}

int main() {
   cout<<nthUglyNumber(6)<<endl; 
}
