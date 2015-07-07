#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > combineHelper(vector<int> nums, int n, int start, int k) {
    vector<vector<int> > result;
    if(n < k)
        return result;
    if(k == n) {
        vector<int> comb;
        for (int i = start; i < start + n; ++i)
        {
            comb.push_back(nums[i]);
        }
        result.push_back(comb);
        return result;
    }
    if(k == 1) {
        for (int i = start; i < start + n; ++i)
        {
            vector<int> comb;
            comb.push_back(nums[i]);
            result.push_back(comb);
        }
        return result;
    }
    vector<vector<int> > thiscombs = combineHelper(nums, n - 1, start + 1, k - 1);
    for (int i = 0; i < thiscombs.size(); ++i)
    {
        thiscombs[i].insert(thiscombs[i].begin(), nums[start]);
        result.push_back(thiscombs[i]);
    }
    vector<vector<int> > nextcombs = combineHelper(nums, n - 1, start + 1, k);
    for (int i = 0; i < nextcombs.size(); ++i)
    {
        result.push_back(nextcombs[i]);
    }
    return result;
}

vector<vector<int> > combine(int n, int k) {
    vector<int> nums;
    for (int i = 0; i < n; ++i)
    {
        nums.push_back(i + 1);
    }
    vector<vector<int> > result;
    result = combineHelper(nums, n, 0, k);
    return result;
}

int main() {
    vector<vector<int> >v = combine(4, 3);
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            cout<<v[i][j]<<'\t';
        }
        cout<<endl;
    }
    return 0;
}