/*************************************************************************
	> File Name: main.cpp
	> Author: 赵泽屹
	> Mail: 
	> Created Time: 2015年07月21日 星期二 14时21分33秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if(n == 0)
        return;
    int it1 = m - 1, it2 = n - 1;
    int i = m + n - 1;
    while(it1 >= 0 && it2 >= 0) {
        if(nums1[it1] > nums2[it2]) {
            nums1[i] = nums1[it1];
            it1--;
        }
        else {
            nums1[i] = nums2[it2];
            it2--;
        }
        i--;
    }
    if(it1 < 0 ) {
        while(it2 >= 0) {
            nums1[i] = nums2[it2];
            it2--;
            i--;
        }
    }
}

int main() {
    return 0;
}
