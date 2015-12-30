/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月30日 星期三 14时24分55秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount){
    int *nums = new int[amount + 1];
    nums[0] = 0;
    int j = 0;
    for(int i = 1; i <= amount; i++){
        nums[i] = -1;
        for(j = 0; j < coins.size(); j++){
            if(i - coins[j] >= 0){
                if(nums[i - coins[j]] != -1 && (nums[i] == - 1 || nums[i - coins[j]] + 1 < nums[i]))
                    nums[i] = nums[i - coins[j]] + 1;
            }
        }
    }
    int change = nums[amount];
    delete[] nums;
    return change;
}

int main(){
    int arr[] = {86,210,29,22,402,140,16,466};
    vector<int> c(begin(arr), end(arr));
    cout<<coinChange(c, 3219)<<endl;
}
