#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums) {
    if(nums.size() <= 1)
        return 0;
    int steps = 0;
    int i = 0;
    while(i < nums.size()) {
        int maxjumppath = 0, index = -1;
        for (int j = 1; j <= nums[i]; ++j)
        {
            if(i + j >= nums.size() - 1) {
                steps ++;
                return steps;
            }
            else {
                if(nums[i + j] + j > maxjumppath) {
                    maxjumppath = nums[i + j] + j;
                    index = i + j;
                }
            }
        }
        i = index;
        steps++;
    }
    return steps;
}

int main() {
    int arr[] = {2,3,1,1,4};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    cout<<jump(v)<<endl;;
    return 0;
}