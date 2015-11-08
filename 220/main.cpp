/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月08日 星期日 11时18分10秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    multimap<long, int>mp;
    for(int i = 0; i < nums.size(); i++) {
        mp.insert(make_pair(nums[i], i));
    }
    multimap<long, int>::iterator it = mp.begin();
    while(it != mp.end()) {
        multimap<long, int>::iterator it1 = it;
        it1++;
        while(it1 != mp.end() && it1->first - it->first <= t) {
            if(abs(it1->second - it->second) <= k)
                return true;
            it1++;
        }
        it++;
    }
    return false;
}

int main() {
    return 0;
}
