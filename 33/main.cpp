#include <iostream>
#include <vector>
using namespace std;

int binarysearch(vector<int>& nums, int target, int low, int high) {
    if(low == -1 || high == -1 || low > nums.size() - 1 || high > nums.size() - 1 || low > high)
        return -1;
    if(low == high && target == nums[low])
        return low;
    else if(low == high && target != nums[low])
        return -1;
    int mid = (low + high) / 2;
    if(nums[mid] == target)
        return mid;
    if(nums[high] == target)
        return high;
    if(nums[mid] < nums[high]) {
        if(nums[mid] > target)
            return binarysearch(nums, target, low, mid - 1);
        else if(nums[mid] < target) {
            if(nums[high] > target) 
                return binarysearch(nums, target, mid + 1, high);
            else if(nums[high] < target)
                return binarysearch(nums, target, low, mid - 1);
        }
    }
    else {
        if(nums[mid] < target) 
            return binarysearch(nums, target, mid + 1, high);
        else if(nums[mid] > target) {
            if(nums[high] > target) 
                return binarysearch(nums, target, mid + 1, high);
            else if(nums[high] < target)
                return binarysearch(nums, target, low, mid - 1);
        }
    }
}

int search(vector<int>& nums, int target) {
    if(nums.empty())
        return -1;
    int index = binarysearch(nums, target, 0, nums.size() - 1);
    return index;
}

int main() {
    int arr[] = {9,0,2,7,8};
    std::vector<int> v(arr, arr + sizeof(arr)/ sizeof(arr[0]));
    cout<<search(v, 3)<<endl;
    return 0;
}