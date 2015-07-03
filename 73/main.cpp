#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int> >& matrix) {
    bool fillrow1 = false, fillcol1 = false;
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            if(matrix[i][j] == 0) {
                if(i == 0)
                    fillrow1 = true;
                if(j == 0)
                    fillcol1 = true;
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < matrix.size(); ++i)
    {
        for (int j = 1; j < matrix[i].size(); ++j)
        {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }
    if(fillrow1)
    {
        for (int i = 0; i < matrix[0].size(); ++i)
        {
            matrix[0][i] = 0;
        }
    }
    if(fillcol1)
    {
        for (int i = 0; i < matrix.size(); ++i)
        {
            matrix[i][0] = 0;
        }
    }
}

int main() {
    return 0;
}