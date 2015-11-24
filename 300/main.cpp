/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月24日 星期二 15时13分15秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if(nums.empty())
        return 0;
    int *l = new int[nums.size()], index = 0, max = 0;
    l[0] = 1;
    for(int i = 1; i < nums.size(); i++) {
        index = i - 1;
        l[i] = 1;
        while(index >= 0) {
            if(nums[index] < nums[i]) {
                if(l[i] < 1 + l[index])
                    l[i] = 1 + l[index];
            }
            index--;
        }
        if(l[i] > max)
            max = l[i];
    }
    delete[] l;
    return max;
}

int main() {
    
}
