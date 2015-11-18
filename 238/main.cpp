/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月17日 星期二 16时15分08秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int> & nums) {
    vector<int> result;
    if(nums.empty())
        return result;
    int pro = 1;
    result.push_back(1);
    for(int i = 1; i < nums.size(); i++) {
        result.push_back(result[i - 1] * nums[i - 1]);
    }
    pro = nums[nums.size() - 1];
    for(int i = nums.size() - 2; i >= 0; i--) {
        result[i] = result[i] * pro;
        pro *= nums[i];
    }
    return result;
}

int main() {
}
