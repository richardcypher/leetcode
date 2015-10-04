#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generate(int numRows) {
    vector<vector<int> >result;
    if(numRows <= 0)
        return result;
    vector<int> row1;
    row1.push_back(1);
    result.push_back(row1);
    for (int i = 2; i <= numRows; ++i)
    {
        vector<int> row;
        row.push_back(1);
        for (int j = 0; j < result[i - 2].size() - 1; ++j)
        {
            row.push_back(result[i - 2][j] + result[i - 2][j + 1]);
        }
        row.push_back(1);
        result.push_back(row);
    }
    return result;
}

int main() {
    return 0;
}