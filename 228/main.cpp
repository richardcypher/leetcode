/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月12日 星期四 16时23分45秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

string num2str(int a) {
    stringstream ss;
    ss<<a;
    return ss.str();
}

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> result;
    if(nums.empty())
        return result;
    int begin = nums[0], end = nums[0] + 1;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] == end) {
            end++;
        }
        else {
            if(begin == end - 1) {
                result.push_back(num2str(begin));
            }
            else {
                result.push_back(num2str(begin) + "->" + num2str(end - 1));
            }
            begin = nums[i];
            end = begin + 1;
        }
    }
    if(begin == end - 1)
        result.push_back(num2str(begin));
    else {
        result.push_back(num2str(begin) + "->" + num2str(end - 1));
    }
    return result;
}

int main() {
    
}
