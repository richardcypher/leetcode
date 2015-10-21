/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月21日 星期三 16时28分47秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

string num2str(int n) {
    stringstream ss;
    ss<<n;
    return ss.str();
}

static bool mysort(int m, int n) {
    string ms = num2str(m), ns = num2str(n);
    return ms + ns > ns + ms;
}

string largestNumber(vector<int>& nums) {
    string str = "";
    if(nums.empty())
        return str;
    sort(nums.begin(), nums.end(), mysort);
    for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        str += num2str(*it);
    if(str[0] == '0' && str.length() > 1)
        return "0";
    return str;
}

int main() {
    return 0;
}
