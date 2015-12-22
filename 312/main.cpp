/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月06日 星期日 08时54分23秒
    动态规划从reverse的角度,考虑最后一个被burst的气球, dp[i,j]=dp[k,j]+dp[i,k]+烧k的coin   
************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

/*int maxC(vector<int>& nums, int n) {
    int max = 0;
    if(n == 1)
        return nums[0];
    else {
        int tmp, restC, total = 0, k;
        for(int i = 0; i < n; i++) {
            total = nums[i];
            if(i > 0)
                total *= nums[i - 1];
            if(i != n - 1)
                total *= nums[i + 1];
            tmp = nums[i];
            for(k = i; k < n - 1; k++)
                nums[k] = nums[k + 1];
            nums[n - 1] = tmp;
            restC = maxC(nums, n - 1);
            total += restC;
            // for(int j = 0; j < n - 1;j++)
            //     cout<<nums[j]<<'\t';
            // cout<<"rest:\t"<<restC<<"\ttotal:"<<total<<endl;
            tmp = nums[n - 1];
            for(k = n - 1; k >= i; k--)
                nums[k] = nums[k - 1];
            nums[i] = tmp;
            if(total > max)
                max = total;
        }
    }
    return max;
}

int maxCoins(vector<int>& nums) {
    return maxC(nums, nums.size());
}*/
int maxCoins(vector<int> & nums) {
    int n = nums.size() + 2;
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    int dp[n][n] = {};
    for (int k = 2; k < n; ++k) {
        for (int left = 0; left < n - k; ++left) {
            int right = left + k;
            for (int i = left + 1; i < right; ++i)
                dp[left][right] = max(dp[left][right],
                     nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right]);
        }
    }

    return dp[0][n - 1];
}

int main(){
    int arr[] = {7,9,8,0,7,1,3,5,5,2,3};
    vector<int> v(arr, arr  + sizeof(arr)/sizeof(arr[0]));
    cout<<maxCoins(v)<<endl;
}
