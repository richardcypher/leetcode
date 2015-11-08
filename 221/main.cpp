/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月08日 星期日 14时13分54秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int maximalSquare(vector<vector<char> >& matrix) {
    if(matrix.empty() || matrix[0].empty())
        return 0;
    int m = matrix.size(), n = matrix[0].size();
    int **length = new int*[m];
    for(int i = 0; i < m; i++) {
        length[i] = new int[n];
    }
    length[0][0] = matrix[0][0] - '0';
    int max = length[0][0];
    for(int i = 1; i < m; i++) {
            length[i][0] = matrix[i][0] - '0';
            if(length[i][0] > max)
                max = length[i][0];
    }
    for(int i = 1; i < n; i++) {
            length[0][i] = matrix[0][i] - '0';
            if(length[0][i] > max)
                max = length[0][i];
    }
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(matrix[i][j] == '0') {
                length[i][j] = 0;
            }
            else {
                length[i][j] = 1;
                for(int k = 0; k < length[i - 1][j - 1]; k++) {
                    if(matrix[i - 1 - k][j] == '1' && matrix[i][j - 1 - k] == '1')
                        length[i][j]++;
                    else
                        break;
                }
            }
            if(length[i][j] > max)
                max = length[i][j];
        }
    }
    return max*max;
}

int main() {
    return 0;
}
