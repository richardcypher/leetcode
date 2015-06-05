#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int> >& matrix) {
    vector<int>  result;
    if(matrix.empty())
        return result;
    int n = matrix.size();
    int m = matrix[0].size();
    if(m == 0)
        return result;
    int min = m < n ? m : n;
    for (int i = 0; i < min / 2; ++i)
    {
        for (int j = i; j < m - i; ++j)
        {
            result.push_back(matrix[i][j]);
        }
        for (int j = i + 1; j < n - i; ++j)
        {
            result.push_back(matrix[j][m - 1 - i]);
        }
        for (int j = m - 2 - i; j >= i; --j)
        {
            result.push_back(matrix[n - 1 - i][j]);
        }
        for (int j = n - 2 - i; j > i; --j)
        {
            result.push_back(matrix[j][i]);
        }
    }
    if(min % 2 != 0) {
        int i = min / 2;
        if(n < m) {
            int length = m - n + 1;
            for (int j = 0; j < length; ++j)
            {
                result.push_back(matrix[i][j + (n  -1) / 2]);
            }
        }
        else {
            int length = n - m  + 1;
            for (int j = 0; j < length; ++j)
            {
                result.push_back(matrix[j + (m - 1) / 2][i]);
            }
        }
    }
    return result;
}

int main() {
    vector<int> v1,v2,v3,v;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v2.push_back(5);
    v2.push_back(6);
    v2.push_back(7);
    v2.push_back(8);
    v3.push_back(9);
    v3.push_back(10);
    v3.push_back(11);
    v3.push_back(12);
    vector<vector<int> >vv;
    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);
    v = spiralOrder(vv);
    for (int i = 0; i < v.size(); ++i)
    {
        cout<<v[i]<<'\t';
    }
    cout<<endl;
    return 0;
}