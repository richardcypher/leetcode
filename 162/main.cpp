/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月18日 星期日 11时30分18秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int findPeakELement(vector<int>& nums) {
    if(nums.empty())
        return -1;
    int low = 0, high = nums.size() - 1, mid;
    while(low != high) {
        mid = (low + high) / 2;
        if(nums[mid] < nums[mid + 1])
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main() {
    return 0;
}
