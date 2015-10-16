/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月16日 星期五 19时07分12秒
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

int helper(vector<int>& nums, int low, int high) {
    if(low == high)
        return nums[low];
    else if(low == high - 1)
        return nums[low] < nums[high] ? nums[low] : nums[high];
    int mid = (low + high) / 2;
    if(nums[mid] > nums[low]) {
        if(nums[mid] > nums[high])
            return helper(nums, mid + 1, high);
        else
            return nums[low];
    }
    else if(nums[mid] < nums[low]) {
        return helper(nums, low, mid);
    }
}

int findMin(vector<int>& nums){
    if(nums.empty())
        return 0;
    return helper(nums, 0, nums.size() - 1);
}
int main() {
    int arr[] = {4,5,6,7,0,1,2};
    vector<int> nums(arr, arr + sizeof(arr)/sizeof(arr[0]));
    cout<<findMin(nums)<<endl;
    return 0;
}
