#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<vector<int> > fourSum(vector<int> &num, int target) {
    std::vector<std::vector<int> > result;
    if(num.size() < 4)
        return result;
    sort(num.begin(), num.end());
    for (int i = 0; i < num.size() - 3; ++i)
    {
        if(i != 0  && num[i] == num[i - 1])
            continue;
        if(num[i] > target && num[i] > 0)
            break;
        int sum1 = target - num[i];
        for (int j = i + 1; j < num.size() - 2; ++j)
        {
            if(j!= i + 1 && num[j] == num[j - 1])
                continue;
            if(num[j] > sum1 && num[j] > 0)
                break;
            int sum2 = sum1 - num[j], left = j + 1, right = num.size() -1;
            while(left < right)
            {
                if(num[left] + num[right] < sum2)
                {
                    left++;
                    while(left < right && num[left] == num[left - 1])
                        left++;
                }
                else if(num[left] + num[right] > sum2)
                {
                    right--;
                    while(left < right && num[right] == num[right+ 1])
                        right--;
                }
                else
                {
                    std::vector<int> v;
                    v.push_back(num[i]);
                    v.push_back(num[j]);
                    v.push_back(num[left]);
                    v.push_back(num[right]);
                    result.push_back(v);
                    left++;
                    while(left < right && num[left] == num[left - 1])
                        left++;
                }
            }
        }
    }
    return result;
}
int main() {
    int arr[] = {1,-2,-5,-4,-3,3,3,5};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    std::vector<std::vector<int> > r = fourSum(v, -11);
    for(int i = 0; i < r.size(); i++) {
        cout<<r[i][0]<<'\t'<<r[i][1]<<'\t'<<r[i][2]<<'\t'<<r[i][3]<<endl;
    }
    return 0;
}