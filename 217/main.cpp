/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月08日 星期日 10时38分00秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool containDuplicate(vector<int>& nums) {
    map<int, bool>mp;
    for(int i = 0; i < nums.size(); i++) {
        if(mp.count(nums[i]) == 0) {
            mp[nums[i]] = true;
        }
        else
            return true;
    }
    return false;
}

int main() {
    return 0;
}
