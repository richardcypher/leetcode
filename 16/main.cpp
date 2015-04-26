#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int threeSumClosest(vector<int> &num, int target) {
    if(num.size() < 3)
    {
        return 0;
    }
    sort(num.begin(), num.end());
    int distance = num[0] + num[1] + num[2] - target;
    for (int i = 0; i < num.size(); ++i)
    {
        int sum = target - num[i], left = i + 1, right = num.size () -1;
        while(left < right)
        {
            int dis = num[left] + num[right] - sum;
            if(dis < 0)
            {
                left++;
                while(left < right && num[left] == num[left - 1])
                    left++;
            }
            else if(dis > 0)
            {
                right--;
                while(left < right && num[right] == num[right + 1])
                    right--;
            }
            else
            {
                return target;
            }
            if(abs(dis) < abs(distance))
                distance = dis;
        }
    }
    return distance + target;
}

int main(){
    int arr[] = {-1,2,1,-4};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    int r = threeSumClosest(v, 1);
    cout<<r<<endl;
    return 0;
}