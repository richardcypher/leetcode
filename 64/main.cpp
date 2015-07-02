#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int> >& grid) {
    if(grid.empty())
        return 0;
    else if(grid[0].empty())
        return 0;
    int m = grid.size(), n = grid[0].size();
    int ** arr = new int*[m];
    for (int i = 0; i < m; ++i)
    {
        arr[i] = new int[n];
    }
    arr[0][0] = grid[0][0];
    for (int i = 1; i < m; ++i)
    {
        arr[i][0] = arr[i  - 1][0] + grid[i][0];
    }
    for (int i = 1; i < n; ++i)
    {
        arr[0][i] = arr[0][i - 1] + grid[0][i];
    }
    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            arr[i][j] = arr[i - 1][j] < arr[i][j - 1] ? arr[i - 1][j] : arr[i][j - 1];
            arr[i][j] += grid[i][j];
        }
    }
    return arr[m - 1][n - 1];
}

int main() {
    int arr1[] = {1,0,0},arr2[]={0,1,0},arr3[]={0,0,1};
    vector<int> v1(arr1, arr1+sizeof(arr1)/sizeof(arr1[0])),
            v2(arr2, arr2+sizeof(arr2)/sizeof(arr2[0])),
            v3(arr3, arr3+sizeof(arr3)/sizeof(arr3[0]));
    vector<vector<int> >v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    cout<<minPathSum(v)<<endl;
    return 0;
}