#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > combinationHelper(vector<int> candidates, int target, int start) {
    vector<vector<int> > combinations;
    if(candidates.empty() || (candidates.size() - 1== start && target % candidates[start] != 0) || candidates[start] > target)
        return combinations;
    if(start == candidates.size() - 1 && target % candidates[start] == 0)
    {
        vector<int> combination;
        for (int i = 0; i < target / candidates[start]; ++i)
        {
            combination.push_back(candidates[start]);
        }
        combinations.push_back(combination);
        return combinations;
    }
    int times = 0;
    while(candidates[start] * times < target) {
        vector<vector<int> > combs = combinationHelper(candidates, target - candidates[start] * times, start + 1);
        for (int i = 0; i < combs.size(); ++i)
        {
            vector<int> comb;
            for (int j = 0; j < times; ++j)
            {
                comb.push_back(candidates[start]);
            }
            for (int j = 0; j < combs[i].size(); ++j)
            {
                comb.push_back(combs[i][j]);
            }
            combinations.push_back(comb);
        }
        times++;
    }
    if(candidates[start] * times == target) {
        vector<int> comb;
        for (int i = 0; i < times; ++i)
        {
            comb.push_back(candidates[start]);
        }
        combinations.push_back(comb);
    }
    return combinations;
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    return combinationHelper(candidates, target, 0);
}

int main() {
    int arr[] = {2,3,6,7};
    vector<int> candidates(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<vector<int> > v = combinationSum(candidates, 7);
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