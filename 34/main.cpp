#include <iostream>
#include <vector>

using namespace std;

int searchEnd(vector<int>& nums, int target, int low, int high) {
    if(low > high)
        return -1;
    int mid = (low + high) / 2;
    if(nums[mid] < target)
        return searchEnd(nums, target, mid + 1, high);
    else if(nums[mid] > target)
        return searchEnd(nums, target, low, mid - 1);
    else {
        int end = searchEnd(nums, target, mid + 1, high);
        if(end == -1)
            return mid;
        else
            return end;
    }
}
int searchStart(vector<int>& nums, int target, int low, int high) {
    if(low > high)
        return -1;
    int mid = (low + high) / 2;
    if(nums[mid] < target)
        return searchStart(nums, target, mid + 1, high);
    else if(nums[mid] > target)
        return searchStart(nums, target, low, mid - 1);
    else {
        int start = searchStart(nums, target, low, mid - 1);
        if(start == -1)
            return mid;
        else
            return start;
    }
}

vector<int> searchRange(vector<int>& nums, int target) {
    std::vector<int> v;
    int start = searchStart(nums, target, 0, nums.size() - 1);
    int end = searchEnd(nums, target,0, nums.size() - 1);
    v.push_back(start);
    v.push_back(end);
    return v;
}

int main() {
    int arr[] = {5, 7, 7, 8, 8, 10};
    std::vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    std::vector<int> v = searchRange(nums, 4);
    cout<<v[0]<<','<<v[1]<<endl;
    return 0;
}