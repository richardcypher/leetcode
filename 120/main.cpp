#include <iostream>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int> >& triangle) {
    if(triangle.empty())
        return 0;
    vector<int> sum(triangle.size(), 0);
    sum[0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); ++i)
    {
        for (int j = triangle[i - 1].size(); j >= 0; --j)
        {
            if(j == triangle[i - 1].size()) {
                sum[j] = triangle[i][j] + sum[j - 1];
            }
            else if(j == 0) {
                sum[j] = triangle[i][j] + sum[j];
            }
            else {
                sum[j] = triangle[i][j] + (sum[j] < sum[j - 1] ? sum[j] : sum[j - 1]);
            }
        }
    }
    int min = sum[0];
    for (int i = 0; i < sum.size(); ++i)
    {
        if(sum[i] < min)
            min = sum[i];
    }
    return min;
}

int main() {
    vector<vector<int> > tria;
    vector<int> row;
    row.push_back(1);
    tria.push_back(row);
    cout<<minimumTotal(tria)<<endl;
    return 0;
}