/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月01日 星期日 14时08分30秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int rob(vector<int>& nums) {
    if(nums.empty())
        return 0;
    int size = nums.size();
    if(size == 1)
        return nums[0];
    else if(size == 2)
        return nums[1] < nums[0] ? nums[0] : nums[1];
    int **money = new int*[size];
    for(int i = 0; i < size; i++) {
        money[i] = new int[size];
    }
    for(int i = 0; i < size - 1; i++) {
        money[i][i] = nums[i];
        money[i][i + 1] = nums[i] < nums[i + 1] ? nums[i + 1] : nums[i];
        for (int j = i + 2; j < size; ++j)
        {
            money[i][j] = money[i][j - 1] < (money[i][j - 2] + nums[j]) ? (money[i][j - 2] + nums[j]) : money[i][j - 1];
        }
    }
    money[size - 1][size - 1] = nums[size - 1];
    return money[0][size - 2] < money[1][size - 1] ? money[1][size - 1] : money[0][size - 2];
}
int main() {
    return 0;
}
