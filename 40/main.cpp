#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > combinationHelper(vector<int> candidates, int target, int start) {
    vector<vector<int> > combinations;
    if(start >= candidates.size() || candidates[start] > target)
        return combinations;
    if(candidates[start] == target) {
        vector<int> combination;
        combination.push_back(target);
        combinations.push_back(combination);
        return combinations;
    }
    vector<vector<int> > combs = combinationHelper(candidates, target - candidates[start], start + 1);
    for (int i = 0; i < combs.size(); ++i)
    {
        vector<int> combination;
        combination.push_back(candidates[start]);
        for (int j = 0; j < combs[i].size(); ++j)
        {
            combination.push_back(combs[i][j]);
        }
        combinations.push_back(combination);
    }
    do{
        start++;
    }while(start >= 1 && start < candidates.size() && candidates[start] == candidates[start - 1]);
    combs = combinationHelper(candidates, target, start);
    if(!combs.empty()) 
        combinations.insert(combinations.end(), combs.begin(), combs.end());
    return combinations;
}

vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    return combinationHelper(candidates, target, 0);
}

int main() {
    int arr[] = {1,1,1,3,3,5};
    vector<int> candidates(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<vector<int> > v = combinationSum2(candidates, 8);
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