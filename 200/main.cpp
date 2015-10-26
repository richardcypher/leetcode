/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月26日 星期一 16时16分31秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
private:
    int *id;
    int *sz;
    int count;
public:
    int find(int p) {
        while(p != id[p]) {
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }

    void myunion(int p, int q) {
        cout<<p<<'\t'<<q<<endl;
        int i = find(p);
        int j = find(q);
        if(i == j)
            return;
        if(sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        }
        else {
            id[j] = i;
            sz[i] += sz[j];
        }
        count--;
    }

    int numIslands(vector<vector<char> >& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        id = new int[m * n];
        sz = new int[m * n];
        for(int i = 0; i < m*n; i++) {
            id[i] = i;
            sz[i] = 1;
        }
        count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    count++;
                    cout<<count<<endl;
                    if(i > 0 && '1' == grid[i - 1][j] && find(i * n + j) != find((i - 1) * n + j)) {
                        myunion(i * n + j, (i - 1) * n + j);
                    }
                    if(i < m - 1 && '1' == grid[i + 1][j] && find(i * n + j) != find((i + 1) * n + j)) {
                        myunion(i * n + j, (i + 1) * n + j);
                    }
                    if(j > 0 && '1' == grid[i][j - 1] && find(i * n + j) != find(i * n + j - 1)) {
                        myunion(i * n + j, i * n + j - 1);
                    }
                    if(j < n - 1 && '1' == grid[i][j + 1] && find(i * n + j) != find(i * n + j + 1)) {
                        myunion(i * n + j, i * n + j + 1);
                    }
                }
            }
        }
        return count;
    }
};

int main() {
    string arr[] = {"11000","11000","00100","00011"};
    vector<vector<char> > grid;
    for(int i = 0; i < 4;i++) {
        vector<char> ch;
        for(int j = 0; j < arr[i].length(); j++)
            ch.push_back(arr[i][j]);
        grid.push_back(ch);
    }
    Solution s;
    cout<<s.numIslands(grid) <<endl;
    return 0;
}
