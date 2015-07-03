#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while(low < high) {
        while(low < nums.size() && nums[low] == 0)
            low++;
        while(high >= 0 && nums[high] != 0)
            high--;
        if(low < high) {
            int tmp = nums[low];
            nums[low] = nums[high];
            nums[high] = tmp;
        }
        low++;
        high--;
    }
    low = 0;
    while(low < nums.size() && nums[low] == 0)
        low++;
    if(low > nums.size() - 1)
        return;
    high = nums.size() - 1;
    while(low < high) {
        while(low < nums.size() && nums[low] == 1)
            low++;
        while(high >= 0 && nums[high] != 1)
            high--;
        if(low < high) {
            int tmp = nums[low];
            nums[low] = nums[high];
            nums[high] = tmp;
        }
        low++;
        high--;
    }
}

int main() {
    return 0;
}