#include <iostream>
#include <vector>

using namespace std;
int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    if(obstacleGrid.empty())
        return 0;
    else if(obstacleGrid[0].empty())
        return 0;
    int n = obstacleGrid[0].size(),m = obstacleGrid.size();
    int ** arr = new int*[m];
    for (int i = 0; i < m; ++i)
    {
        arr[i] = new int[n];
    }
    arr[0][0] = (obstacleGrid[0][0] == 1) ? 0 : 1;
    for (int i = 1; i < m; ++i)
    {
        arr[i][0] = obstacleGrid[i][0] == 0 ? arr[i - 1][0] : 0;
    }
    for (int i = 1; i < n; ++i)
    {
        arr[0][i] = obstacleGrid[0][i] == 0 ? arr[0][i - 1] : 0;
    }
    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            arr[i][j] = obstacleGrid[i][j] == 1 ? 0 : (arr[i - 1][j] + arr[i][j - 1]);
        }
    }
    int result = arr[m-1][n -1];
    return result;
}
int main() {
    int arr1[] = {0,0,0},arr2[]={0,1,0},arr3[]={0,0,0};
    vector<int> v1(arr1, arr1+sizeof(arr1)/sizeof(arr1[0])),
            v2(arr2, arr2+sizeof(arr2)/sizeof(arr2[0])),
            v3(arr3, arr3+sizeof(arr3)/sizeof(arr3[0]));
    vector<vector<int> >v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    cout<<uniquePathsWithObstacles(v)<<endl;
    return 0;
}