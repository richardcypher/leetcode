/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月25日 星期日 11时18分15秒
    1.复制一遍数组,删除多余
    2.两边分别倒置,然后整体倒置
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    int i = 0, j = n - k - 1;
    while(i < j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--;
    }
    i = n - k;
    j = n - 1;
    while(i < j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--;
    }
    i = 0;
    j = n - 1;
    while(i < j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--;
    }
}

int main() {
    return 0;
}
