#include <iostream>
#include <vector>

using namespace std;

int binarysearch(vector<int>& nums, int target, int low, int high) {
    if(low >= high) {
        if(target <= nums[low])
            return low;
        else if(target > nums[low])
            return low + 1;
    }
    int mid = (low + high) / 2;
    if(nums[mid] < target)
        return binarysearch(nums, target, mid + 1, high);
    else if(nums[mid] > target)
        return binarysearch(nums, target, low, mid - 1);
    else
        return mid;
}

int searchInsert(vector<int>& nums, int target) {
    int index = binarysearch(nums, target, 0, nums.size() - 1);
    return index;
}

int main() {
    int arr[] = {1,3};
    std::vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    int i= searchInsert(nums, 0);
    cout<<i<<endl;
    return 0;
}