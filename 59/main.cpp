#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > result;
    if(n <= 0)
        return result;
    for (int i = 0; i < n; ++i)
    {
        std::vector<int> v(n, 0);
        result.push_back(v);
    }
    int val = 1;
    for (int i = 0; i < n / 2; ++i)
    {
        for (int j = i; j < n - 1 - i; ++j)
        {
            result[i][j] = val++;
        }
        for (int j = i; j < n - 1 - i; ++j)
        {
            result[j][n - 1 - i] = val++;
        }
        for (int j = n - 1 - i; j > i; --j)
        {
            result[n - 1 - i][j] = val++;
        }
        for (int j = n - 1 - i; j > i; --j)
        {
            result[j][i] = val++;
        }
    }
    if(n % 2 != 0){
        result[n / 2][n / 2] = val;
    }
    return result;
}

int main(){
    std::vector<std::vector<int> > v = generateMatrix(5);
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