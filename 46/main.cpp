#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > permuteHelper(vector<int>& nums, int index) {
    std::vector<std::vector<int> > result;
    if(index <0 || index >= nums.size())
        return result;
    else if(index == nums.size() - 1) {
        std::vector<int> perm;
        perm.push_back(nums[index]);
        result.push_back(perm);
        return result;
    }
    for (int i = index; i < nums.size(); ++i)
    {
        int tmp = nums[i];
        nums[i] = nums[index];
        nums[index] = tmp;
        std::vector<std::vector<int> > next = permuteHelper(nums, index + 1);
        for (int n = 0; n < next.size(); ++n)
        {
            vector<int> perm;
            perm.push_back(nums[index]);
            for (int j = 0; j < next[n].size(); ++j)
            {
                perm.push_back(next[n][j]);
            }
            result.push_back(perm);
        }
        tmp = nums[i];
        nums[i] = nums[index];
        nums[index] = tmp;
    }
    return result;
}

vector<vector<int> > permute(vector<int>& nums) {
    std::vector<std::vector<int> > result;
    if(nums.empty())
        return result;
    result = permuteHelper(nums, 0);
    return result;
}

int main() {
    int arr[] = {1,2,3};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<vector<int> >v = permute(nums);
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