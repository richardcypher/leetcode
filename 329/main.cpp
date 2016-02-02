/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年02月01日 星期一 11时51分39秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

void longestPath(vector<vector<int> >& matrix, vector<vector<int> >& visited, int i, int j){
    int m = matrix.size(), n = matrix[0].size();
    if(visited[i][j])
        return;
    visited[i][j] = 1;
    if(i > 0 && matrix[i][j] < matrix[i - 1][j]) {
        if(!visited[i - 1][j])
        {
            longestPath(matrix, visited, i - 1, j);
        }
        visited[i][j] = visited[i][j] > (1 + visited[i - 1][j]) ? visited[i][j] : (1 + visited[i - 1][j]);
    }
    if(j > 0 && matrix[i][j] < matrix[i][j - 1]) {
        if(!visited[i][j - 1])
            longestPath(matrix, visited, i, j - 1);
        visited[i][j] = visited[i][j] > (1 + visited[i][j - 1]) ? visited[i][j] : (1 + visited[i][j - 1]);
    }
    if(i < m - 1 && matrix[i][j] < matrix[i + 1][j]) {
        if( !visited[i + 1][j])
            longestPath(matrix, visited, i + 1, j);
        visited[i][j] = visited[i][j] > (1 + visited[i + 1][j]) ? visited[i][j] : (1 + visited[i + 1][j]);
    }
    if(j < n - 1 && matrix[i][j] < matrix[i][j + 1]) {
        if(!visited[i][j + 1])
            longestPath(matrix, visited, i, j + 1);
        visited[i][j] = visited[i][j] > (1 + visited[i][j + 1]) ? visited[i][j] : (1 + visited[i][j + 1]);
    }
}

int longestIncreasingPath(vector<vector<int> >& matrix){
    if(matrix.empty() || matrix[0].empty())
        return 0;
    int length = 1, max = 0;
    int i, j, m = matrix.size(), n = matrix[0].size(), vi, vj;
    vector<vector<int> > visited;
    for(vi = 0; vi < m; vi++){
        vector<int> v;
        for(vj = 0; vj < n; vj++) {
            v.push_back(0);
        }
        visited.push_back(v);
    }
    for(i = 0; i < m ; i++){
        for(j = 0; j < n; j++){
            longestPath(matrix, visited, i, j);
            max = visited[i][j];
            if(max > length)
                length = max;
        }
    }
    return length;
}

int main(){
    vector<vector<int> > ma;
    int v[15][10] = {{0,1,2,3,4,5,6,7,8,9},{19,18,17,16,15,14,13,12,11,10},{20,21,22,23,24,25,26,27,28,29},{39,38,37,36,35,34,33,32,31,30},{40,41,42,43,44,45,46,47,48,49},{59,58,57,56,55,54,53,52,51,50},{60,61,62,63,64,65,66,67,68,69},{79,78,77,76,75,74,73,72,71,70},{80,81,82,83,84,85,86,87,88,89},{99,98,97,96,95,94,93,92,91,90},{100,101,102,103,104,105,106,107,108,109},{119,118,117,116,115,114,113,112,111,110},{120,121,122,123,124,125,126,127,128,129},{139,138,137,136,135,134,133,132,131,130},{0,0,0,0,0,0,0,0,0,0}};
    // int v[4][4] = {{7,6,1,1},{2,7,6,0},{1,3,5,1},{6,6,3,2}};
    for(int i = 0; i < 15; i ++){
        vector<int> m;
        for(int j = 0; j < 10; j++)
            m.push_back(v[i][j]);
        ma.push_back(m);
    }
    cout<<longestIncreasingPath(ma)<<endl;
}
