#include <vector>
#include <iostream>

using namespace std;

void rotate(vector<vector<int> >& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; ++i)
    {
        for (int j = 0; j < n - 1 - 2 * i ; ++j)
        {
            int tmp = matrix[i][i + j];
            matrix[i][i + j] = matrix[n - 1 - i - j][i];
            matrix[n - 1 - i - j][i] = matrix[n - 1 - i][n - 1 -  i - j];
            matrix[n - 1 - i][n - 1 - i - j] = matrix[i + j][n - 1 - i];
            matrix[i + j][n - 1 - i] = tmp;
        }
    }
}

int main () {
    vector<int> v1, v2,v3,v4;
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
    v4.push_back(13);
    v4.push_back(14);
    v4.push_back(15);
    v4.push_back(16);
    std::vector<std::vector<int> > v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    rotate(v);
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