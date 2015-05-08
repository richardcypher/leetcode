#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    if(nums.empty() || nums.size() == 1)
        return;
    int index = nums.size() - 1;
    int max = nums[index];
    while(index >=0 && max <= nums[index]) {
        max = nums[index];
        index--;
    }
    sort(nums.begin() + index + 1, nums.end());
    if(index == -1)
        return;
    for (int i = index + 1; i < nums.size(); ++i)
    {
        if(nums[index] < nums[i]) {
            int tmp = nums[index];
            nums[index] = nums[i];
            nums[i] = tmp;
            break;
        }
    }
}

int main() {
    int arr[] = {1,1,5};
    std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    nextPermutation(v);
    for (int i = 0; i < v.size(); ++i)
    {
        cout<<v[i]<<'\t';
    }
    cout<<endl;
    return 0;
}