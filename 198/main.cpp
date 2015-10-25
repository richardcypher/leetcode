/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月25日 星期日 13时14分28秒
    r[i] = max{r[i - 1], r[i - 2] + nums[i]}
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int rob(vector<int>& nums) {
    if(nums.empty())
        return 0;
    int size = nums.size();
    int *money = new int[size];
    money[0] = nums[0];
    money[1] = nums[1] < nums[0] ? nums[0] : nums[1];
    for(int i = 2; i < size; i++) {
        money[i] = money[i - 1] > (money[i - 2] + nums[i]) ? money[i - 1] : (money[i - 2] + nums[i]);
    }
    return money[size - 1];
}

int main() {
    return 0;
}
