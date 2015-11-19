/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月19日 星期四 11时03分54秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<int> singleNumber(vector<int> & nums) {
    vector<int> result;
    int data = 0;
    for(int i = 0; i < nums.size(); i++)
        data ^= nums[i];
    int bitindex = 0;

    for(; bitindex < 32; bitindex++) {
        if((data >> bitindex) & 1) {
            break;
        }
    }
    int num1 = 0, num2 = 0;
    for(int i = 0; i < nums.size(); i++) {
        if((nums[i] >> bitindex) & 1)
            num1 ^= nums[i];
        else
            num2 ^= nums[i];
    }
    result.push_back(num1);
    result.push_back(num2);
    return result;
}

int main() {
    
}
