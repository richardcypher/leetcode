#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > combineHelper(vector<int> & nums, int n, int start, int k, bool dupe) {
    vector<vector<int> > result;
    if (n < k)
        return result;
    if (k == n) {
        if(!dupe) {
            vector<int> comb;
            for (int i = start; i < start + n; ++i)
            {
                comb.push_back(nums[i]);
            }
            result.push_back(comb);
        }
        return result;
    }
    if (k == 1) {
        for (int i = start; i < start + n; ++i)
        {
            if (!result.empty() && nums[i] == result[result.size() - 1][0])
                continue;
            vector<int> comb;
            comb.push_back(nums[i]);
            result.push_back(comb);
        }
        return result;
    }
    vector<vector<int> > nextcombs;
    if (start < nums.size() - 1 && nums[start] != nums[start + 1]) {
        nextcombs = combineHelper(nums, n - 1, start + 1, k, false);
    }
    else
        nextcombs = combineHelper(nums, n - 1, start + 1, k, true);
    for (int i = 0; i < nextcombs.size(); ++i)
    {
        result.push_back(nextcombs[i]);
    }
    if(!dupe) {
        vector<vector<int> > thiscombs = combineHelper(nums, n - 1, start + 1, k - 1, false);
        for (int i = 0; i < thiscombs.size(); ++i)
        {
            thiscombs[i].insert(thiscombs[i].begin(), nums[start]);
            result.push_back(thiscombs[i]);
        }
    }
    return result;
}

vector<vector<int> > subsetsWithDup(vector<int>& nums) {
    vector<vector<int> >result;
    vector<int> empty;
    result.push_back(empty);
    if (nums.empty())
        return result;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 1; i <= n; ++i)
    {
        vector<vector<int> > subset = combineHelper(nums, n, 0, i, false);
        result.insert(result.end(), subset.begin(), subset.end());
    }
    return result;
}

int main() {
    int arr[] = {1,1,2,2 };
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<vector<int> > r = subsetsWithDup(v);
    for (int i = 0; i < r.size(); ++i)
    {
        for (int j = 0; j < r[i].size(); ++j)
        {
            cout << r[i][j] << '\t';
        }
        cout << endl;
    }
    return 0;
}