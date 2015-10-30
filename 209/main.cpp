/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月30日 星期五 11时16分00秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
    int size = nums.size(), sum = 0, low = 0, high = 0, length = size + 1;
    for(int i = 0; i < size; i++) {
        sum += nums[i];
        high = i;
        while(sum >= s && low <= high) {
            if(high - low + 1 < length)
                length = high - low  + 1;
            sum = sum - nums[low];
            low++;
        }
    }
    return length;
}

int main() {
    return 0;
}
