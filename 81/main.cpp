#include <iostream>
#include <vector>

using namespace std;

bool binarysearch(vector<int>& nums, int target, int low, int high) {
        if(low == -1 || high == -1 || low > nums.size() - 1 || high > nums.size() - 1 || low > high)
        return false;
    if(low == high && target == nums[low])
        return true;
    else if(low == high && target != nums[low])
        return false;
    int mid = (low + high) / 2;
    if(nums[mid] == target || nums[high] == target)
        return true;
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
    else if(nums[mid] == nums[high]) {
        return binarysearch(nums, target, low, mid - 1) || binarysearch(nums, target, mid + 1, high);
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

bool search(vector<int>& nums, int target) {
    if(nums.empty())
        return false;
    return binarysearch(nums, target, 0, nums.size() - 1);
}

int main() {
    return 0;
}