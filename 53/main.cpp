#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    if(nums.empty())
        return 0;
    int sum = 0, max = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];
        if(sum < 0)
            sum = 0;
        if(sum > max)
            max = sum;
    }
    if(max == 0) {
        max = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] > max)
                max = nums[i];
        }
    }
    return max;
}

int main() {
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    cout<<maxSubArray(v)<<endl;
    return 0;
}