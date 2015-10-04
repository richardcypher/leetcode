#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> row;
    if(rowIndex < 0)
        return row;
    row.push_back(1);
    int ss = 1;
    for (int i = 1; i <= rowIndex; ++i)
    {
        ss = row.size();
        for (int j = ss - 1; j >= 1; --j)
        {
            row[j] = row[j - 1] + row[j];
        }
        row.push_back(1);
    }
    return row;
}

int main() {
    return 0;
}