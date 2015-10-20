/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月20日 星期二 21时04分26秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int majorityELement(vector<int>& nums) {
    int num, times = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(times == 0)
            num = nums[i];
        if(num == nums[i])
            times++;
        else
            times--;
    }
    return num;
}

int main() {
    return 0;
}
