/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月12日 星期四 16时54分49秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


vector<int> majorityElement(vector<int>& nums) {
    vector<int> result;
    if(nums.empty())
        return result;
    int num1, num2, times1 = 0, times2 = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(times1 == 0) {
            if(times2 == 0 || nums[i] != num2)
                num1 = nums[i];
        }
        else if(times2 == 0) {
            if(times1 == 0 || nums[i] != num1)
                num2 = nums[i];
        }
        if(nums[i] == num1) {
            times1++;
        }
        else if(nums[i] == num2){
            times2++;
        }
        else {
            times1--;
            times2--;
        }
    }
    int t1 = 0, t2 = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(times1 > 0 && num1 == nums[i])
            t1++;
        if(times2 > 0 && num2 == nums[i])
            t2++;
    }
    if(t1 > nums.size() / 3)
        result.push_back(num1);
    if(t2 > nums.size() / 3)
        result.push_back(num2);
    return result;
}

int main() {
    int arr[] = {-1,1,1,1,2,1};
    vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));
    majorityElement(v);
}
