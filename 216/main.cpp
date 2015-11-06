/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月06日 星期五 15时46分52秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

void combinationHelper(int k, int n, vector<int> seq, int sum, int start, vector<vector<int> > & result) {
    if(seq.size() == k && sum == n) {
        result.push_back(seq);
    }
    else if(seq.size() < k && sum < n) {
        for(int i = start; i <= 9; i++) {
            seq.push_back(i);
            sum += i;
            combinationHelper(k, n, seq, sum, i + 1, result);
            sum -= i;
            seq.erase(seq.end() - 1);
        }
    }
}
vector<vector<int> > combinationSum3(int k, int n) {
    vector<int> seq;
    vector<vector<int> > result;
    int sum = 0;
    combinationHelper(k, n, seq, sum, 1, result);
    return result;
}

int main() {
    vector<vector<int> >r = combinationSum3(3, 9);
    for(int i = 0; i < r.size(); i++) {
        for(int j = 0; j < r[i].size(); j++)
            cout<<r[i][j]<<'\t';
        cout<<endl;
    }
    return 0;
}
