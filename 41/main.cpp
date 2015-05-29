#include <iostream>
#include <vector>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int size = nums.size();
    for (int i = 0; i < size; ++i)
     {
        while(nums[i] > 0 && nums[i] <= size && nums[i] != nums[nums[i] - 1]) {
            int tmp = nums[i];
            nums[i] = nums[nums[i] - 1];
            nums[tmp - 1] = tmp;
        }
     }
     for (int i = 0; i < size; ++i)
     {
         if(nums[i] != i + 1)
            return i+1;
     }
     return size +  1;
}

int main() {
    int arr[] = {3,4,-1,1};
    vector<int> nums(arr, arr + sizeof(arr)/sizeof(arr[0]));
    int num =  firstMissingPositive(nums);
    cout<<num<<endl;
    return 0;
}