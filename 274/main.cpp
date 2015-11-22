/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月22日 星期日 21时43分50秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int hIndex(vector<int>& citations) {
    if(citations.empty())
        return 0;
    int h = 0, n = citations.size();
    vector<int> cites(n, 0);
    for(int i = 0; i < n; i++) {
        if(citations[i] > n)
            cites[n - 1]++;
        else if(citations[i] > 0)
            cites[citations[i] - 1]++;
    }
    int cs = 0;
    for(h = cites.size() - 1; h >= 0; h--) {
        cs += cites[h];
        if(cs >= h + 1)
            break;
    }
    return h + 1;
}

int main(){
    vector<int> c;
    c.push_back(3);
    cout<<hIndex(c)<<endl;
}
