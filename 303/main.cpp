/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月24日 星期二 15时36分36秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class NumArray {
private:
    int *arr;
    int length;
public:
    NumArray(vector<int> & nums) {
        if(nums.empty())
            return;
        length = nums.size();
        arr = new int[length];
        arr[0] = nums[0];
        for(int i = 1; i < length; i++){
            arr[i] = arr[i - 1]  + nums[i];
        }
    }

    int sumRange(int i, int j) {
        if(i >= length || j >= length)
            return 0;
        if(i == 0)
            return arr[j];
        else
            return arr[j] - arr[i - 1];
    }
};

int main(){}
