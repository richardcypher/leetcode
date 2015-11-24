#include<iostream>
#include<vector>

class NumMatrix {
private:
    int **arr;
    int m;
    int n;
public:
    NumMatrix(vector<vector<int> >& matrix) {
        int i = 0, j = 1;
        m = matrix.size(), n = 0;
        if(m > 0)
            n = matrix[i].size();
        arr = new int*[m];
        for(; i < m; i++) {
            arr[i] = new int[n];
            if(i == 0)
                arr[i][0] = matrix[0][0];
            else
                arr[i][0] = arr[i - 1][0] + matrix[i][0];
        }
        for(; j < n; j++)
            arr[0][j] = arr[0][j - 1] + matrix[0][j];
        for(i = 1; i < m; i++) {
            for(j = 1; j < n; j++) {
                arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 < 0 || row1 > m || col1 < 0 || col1 > n || row2 < 0 ||
            row2 > m || col2 < 0 || col2 > n)
            return 0;
        int sum = arr[row2][col2];
        if(row1 == 0 && col1 == 0)
            return sum;
        else if(row1 == 0)
            return sum - arr[row2][col1 - 1];
        else if(col1 == 0)
            return sum - arr[row1 - 1][col2];
        else
            return sum - arr[row1 - 1][col2] - arr[row2][col1 - 1] + arr[row1 - 1][col1 - 1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

int main(){}