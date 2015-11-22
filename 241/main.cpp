/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月19日 星期四 10时13分42秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> diffWaysToCompute(string input) {
    vector<int> nums;
    vector<char> ops;
    int index = 0, num = 0;
    while(index < input.length()) {
        if(input[index] == '+' || input[index] == '-' || input[index] == '*')
            ops.push_back(input[index]);
        else if(input[index] >= '0' && input[index] <= '9') {
            num = (input[index] - '0') + num * 10;
            if(index == input.length() - 1 || input[index + 1] < '0' || input[index + 1] > '9') {
                nums.push_back(num);
                num = 0;
            }
        }
        index++;
    }
    int n = nums.size();
    vector<int> ** C = new vector<int>*[n];
    for(int i = 0; i < n; i++) {
        C[i] = new vector<int>[n];
        C[i][i].push_back(nums[i]);
    }
    for(int s = 1; s <= n - 1; s++) {
        for(int i = 0; i < n - s; i++) {
            int j = i + s;
            for(int k = i + 1; k <= j; k++) {
                for(int tk1 = 0; tk1 < C[i][k - 1].size(); ++tk1)
                {
                    for(int tk2 = 0; tk2 < C[k][j].size(); ++tk2)
                    {
                        char op = ops[k - 1];
                        if(op == '+')
                            C[i][j].push_back(C[i][k - 1][tk1] + C[k][j][tk2]);
                        else if(op == '-')
                            C[i][j].push_back(C[i][k - 1][tk1] - C[k][j][tk2]);
                        else if(op == '*')
                            C[i][j].push_back(C[i][k - 1][tk1] * C[k][j][tk2]);
                    }
                }
            }
        }
    }
    return C[0][n - 1];
}

int main() {
    
}
