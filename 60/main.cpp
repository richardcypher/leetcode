#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
int factorial(int n) {  
    if (n == 1)
        return 1; 
    else if(n == 0)
        return 0;
    return factorial(n-1)*n;  
}  
string permHelper(vector<int>& nums, int index, int k) {
    if(index < 0 || index >= nums.size())
        return "";
    int num = factorial(nums.size() - index - 1);
    if(num == 0) {
        stringstream ss;
        ss<<nums[k -1];
        return ss.str();
    }
    if(k > num * nums.size())
        return "";
    int times = (k - 1 ) / num;
    stringstream ss;
    ss<<nums[times];
    string str = ss.str();
    k = k - (num * times);
    nums.erase(nums.begin() + times);
    return str + permHelper(nums, index, k);
}

string getPermutation(int n, int k) {
    std::vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        v.push_back(i + 1);
    }
    string str = permHelper(v, 0, k);
    return str;
}

int main() {
    string str = getPermutation(1, 1);
    cout<<str<<endl;
    return 0;
}