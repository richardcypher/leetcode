/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月05日 星期四 15时57分29秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int select(vector<int>& nums, int k) {
    if(nums.size() <= 5) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
    vector<int> mids;
    int n = ceil(nums.size() / 5);
    for(int i = 0; i < n; i++) {
        vector<int> tmp;
        for(int j = 0; j < 5; j++) {
            if(i * 5 + j < nums.size())
                tmp.push_back(nums[i * 5 + j]);
        }
        if(tmp.size() < 5)
            break;
        sort(tmp.begin(), tmp.end());
        mids.push_back(tmp[2]);
    }
    int mid = select(mids, ceil(mids.size() / 2.0));
    vector<int> A1, A2, A3;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] < mid)
            A1.push_back(nums[i]);
        else if(nums[i] == mid)
            A2.push_back(nums[i]);
        else
            A3.push_back(nums[i]);
    }
    if(A3.size() >= k)
        return select(A3, k);
    else if(A3.size() < k && A2.size() + A3.size() >= k)
        return mid;
    else if(A2.size() + A3.size() < k)
        return select(A1, k - A3.size() - A2.size());
}

int findKthLargest(vector<int>& nums, int k) {
    return select(nums, k);
}

int main() {
    int arr[] = {3,2,1,5,6,4};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    cout<<findKthLargest(nums, 2)<<endl;
    return 0;
}
