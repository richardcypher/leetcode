#include <iostream>
#include <vector>
#include <algorithm>

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

vector<vector<int> > subsets(vector<int>& nums) {
    vector<vector<int> >result;
    vector<int> empty;
    result.push_back(empty);
    if(nums.empty())
        return result;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 1; i <= n; ++i)
    {
        vector<vector<int> > subset = combineHelper(nums, n, 0, i);
        result.insert(result.end(), subset.begin(), subset.end());
    }
    return result;
}

int main() {
    return 0;
}