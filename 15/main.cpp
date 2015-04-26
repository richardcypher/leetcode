#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > result;
    if(num.size() < 3)
        return result;
    sort(num.begin(), num.end());
    for (int i = 0; i < num.size() - 1; ++i)
    {
        if(i != 0 && num[i] == num[i - 1])
            continue;
        if(num[i] > 0)
            break;
        int sum = 0 - num[i], left = i + 1, right = num.size() - 1;
        while(left < right) {
            if(num[left] + num[right] > sum) {
                right--;
                while(num[right] == num[right + 1] && right > left)
                    right--;
            }
            else if(num[left] + num[right] < sum) {
                left++;
                while(num[left] == num[left - 1] && left < right)
                    left++;
            }
            else
            {
                std::vector<int> v;
                v.push_back(num[i]);
                v.push_back(num[left]);
                v.push_back(num[right]);
                result.push_back(v);
                left++;
                while(num[left] == num[left - 1] && left < right)
                    left++;
            }
        }
    }
    return result;
}

int main() {
     //int arr[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    int arr[] = {3,2,-1,-3,-5,0,-5,-4,-4,2,3};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    std::vector<std::vector<int> > r = threeSum(v);
    for(int i = 0; i < r.size(); i++) {
        cout<<r[i][0]<<'\t'<<r[i][1]<<'\t'<<r[i][2]<<endl;
    }
    return 0;
}