/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月19日 星期日 16时52分32秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.size() <= 1)
        return nums.size();
    int size = 1;
    bool dupe = false;
    for (int i = 1; i < nums.size(); ++i)
    {
        if(nums[i] != nums[i - 1]) {
            nums[size] = nums[i];
            size++;
            dupe = false;
        }
        else if(!dupe) {
            nums[size] = nums[i];
            dupe = true;
            size++;
        }
        else {

        }
    }
    return size;
}

int main() {
    int arr[] = {1,1,1,2,2,3};
    vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));
    int n = removeDuplicates(v);
    cout<<n<<endl;
    for (int i = 0; i < n; ++i)
    {
        cout<<v[i]<<'\t';
    }
    cout<<endl;
}
