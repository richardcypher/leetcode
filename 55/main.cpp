/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月06日 星期六 01时06分02秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    if(nums.empty())
        return false;
    if(nums.size() == 1)
        return true;
    int i = 0;
    while(i < nums.size() - 1) {
        if(nums[i] == 0)
            return false;
        int max = 0, next = 0;
        for (int j = 1; j <= nums[i]; ++j)
        {
            if(i + j >= nums.size() - 1)
                return true;
            if(nums[i + j] == 0)
                continue;
            if(max < j + nums[i + j]) {
                max = j + nums[i + j];
                next = i + j;
            }
        }
        if(next == 0)
            return false;
        i = next;
    }
    return true;
}

int main() {
    int arr[] = {2,3,1,1,4};
    std::vector<int> v(arr, arr + sizeof(arr)/ sizeof(arr[0]));
    cout<<canJump(v)<<endl;
    return 0;
}
