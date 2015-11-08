/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月08日 星期日 10时43分30秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    map<int, int>mp;
    for(int i = 0; i < nums.size(); i++) {
        if(mp.count(nums[i]) != 0 && i - mp[nums[i]] <= k)
            return true;
        mp[nums[i]] = i;
    }
    return false;
}

int main() {
    return 0;
}
