#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int low = 0, high = matrix.size() - 1, mid = (low + high) / 2;
    while(low <= high) {
        if(matrix[mid][0] < target) {
            low = mid + 1;
            mid = (low + high) / 2;
        }
        else if(matrix[mid][0] > target) {
            high = mid - 1;
            mid = (low + high) / 2;
        }
        else
            return true;
    }
    int row = mid;
    low = 0, high = matrix[row].size() - 1, mid = (low + high) / 2;
    while(low <= high) {
        if(matrix[row][mid] < target) {
            low = mid + 1;
            mid = (low + high) / 2;
        }
        else if(matrix[row][mid] > target) {
            high = mid - 1;
            mid = (low + high) / 2;
        }
        else
            return true;
    }
    return false;
}

int main() {
    return 0;
}