/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月16日 星期五 16时26分48秒

    >pos表示到当前数字为止的正数乘积，nag表示到当前数字为止的负数乘积
    每次循环更新pos和neg的值，使得绝对值尽可能大
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int maxProduct(vector<int>& nums) {
    if(nums.empty())
        return 0;
    if(nums.size() == 1)
        return nums[0];
    int maxP = nums[0], nag = 1, pos = -1, tmp;
    for (int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] > 0)
        {
            nag *= nums[i];
            pos *= nums[i];
            nag = nag > 1 ? 1 : nag;
            pos = pos > nums[i] ? pos : nums[i];
            if(maxP < pos)
                maxP = pos;
        }
        else if(nums[i] < 0)
        {
            tmp = nag;
            nag = pos * nums[i];
            pos = tmp * nums[i]; 
            nag = nag < nums[i] ? nag : nums[i];
            pos = pos > -1 ? pos : -1;
            if(maxP < pos)
                maxP = pos;
        }
        else 
        {
            pos = -1;
            nag = 1;
            if(maxP < 0)
                maxP = 0;
        }
    }
    return maxP;
}

int main() {
    return 0;
}
