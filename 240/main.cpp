/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月18日 星期三 10时00分28秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int m = matrix.size();
    if(m == 0)
        return false;
    int n = matrix[0].size();
    int strictm = 0, strictn = 0;
    int low = 0, high = m - 1, mid = 0;
    while(low <= high) {
        mid = (low + high) / 2;
        if(matrix[mid][0] < target)
            low = mid + 1;
        else if(matrix[mid][0] > target)
            high = mid - 1;
        else
            return true;
    }
    strictm = mid;
    if(matrix[strictm][0] > target)
        strictm--;
    low = 0; high = n - 1;
    while(low <= high) {
        mid = (low + high) / 2;
        if(matrix[0][mid] < target)
            low = mid + 1;
        else if(matrix[0][mid] > target)
            high = mid - 1;
        else
            return true;
    }
    strictn = mid;
    if(matrix[0][strictn] > target)
        strictn--;
    for(int i = 0; i <= strictm; i++) {
        low = 0;
        high = strictn;
        while(low <= high) {
            mid = (low + high) / 2;
            if(matrix[i][mid] < target)
                low = mid + 1;
            else if(matrix[i][mid] > target) {
                high = mid - 1;
                strictn = high;
            }
            else
                return true;
        }
    }
    return false;
}

int main(){
    
}
