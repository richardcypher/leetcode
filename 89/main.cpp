#include <iostream>
#include <vector>

using namespace std;

vector<int> grayCode(int n) {
    vector<int> result;
    if(n == 0) {
        result.push_back(0);
        return result;
    }
    else if (n == 1) {
        result.push_back(0);
        result.push_back(1);
        return result;
    }
    int addnum = 1;
    for (int i = 1; i < n; ++i)
    {
        addnum *= 2;
    }
    vector<int> lastresult = grayCode(n - 1);
    result.insert(result.end(), lastresult.begin(), lastresult.end());
    for (int i = lastresult.size() - 1; i >= 0 ; --i)
    {
        result.push_back(lastresult[i] + addnum);
    }
    return result;
}

int main() {
    std::vector<int> v = grayCode(3);
    for (int i = 0; i < v.size(); ++i)
    {
        cout<<v[i]<<'\t';
    }
    cout<<endl;
    return 0;
}