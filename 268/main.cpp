/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月22日 星期日 17时35分16秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size(), r = n;
    for(int i = 0; i < n; i++) {
        r ^= i;
        r ^= nums[i];
    }
    return r;
}

int main() {
    
}
