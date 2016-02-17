/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年02月17日 星期三 11时17分47秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

bool increasingTriplet(vector<int>& nums) {
    int c1 = INT_MAX, c2 = INT_MAX;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] <= c1) {
            c1 = nums[i];
        }
        else if(nums[i] <= c2) {
            c2 = nums[i];
        }
        else
            return true;
    }
    return false;
}

int main(){}
