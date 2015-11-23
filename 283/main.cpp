/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月23日 星期一 10时55分39秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int i = 0, j = 0;
    for(; i < nums.size(); i++) {
        if(nums[i] != 0) {
            nums[j] = nums[i];
            j++;
        }
    }
    for(; j < nums.size(); j++)
        nums[j] = 0;
}

int main(){}
