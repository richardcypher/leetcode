/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年02月02日 星期二 15时56分26秒
    Let miss be the smallest sum in [0,n] that we might be missing. 
    Meaning we already know we can build all sums in [0,miss). 
    Then if we have a number num <= miss in the given array, 
    we can add it to those smaller sums to build all sums in [0,miss+num).
     If we don't, then we must add such a number to the array, 
     and it's best to add miss itself, to maximize the reach.
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int minPatches(vector<int>& nums, int n) {
    long miss = 1, added = 0, i = 0, size = nums.size();
    while(miss <= n) {
        if(i < size && nums[i] <= miss) {
            miss += nums[i++];
        }
        else {
            miss <<= 1;
            added++;
        }
    }
    return added;
}

int main(){}
