/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月23日 星期一 16时58分56秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

void gameOfLife(vector<vector<int> >& board) {
    int m = board.size();
    if(m == 0)
        return;
    int n = board[0].size();
    int livecell = 0, deadcell = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            livecell = 0;
            deadcell = 0;
            if(i > 0) {
                if(board[i - 1][j] == 1 || board[i - 1][j] == 2)
                    livecell++;
                if(j > 0) {
                    if(board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == 2)
                        livecell++;
                }
                if(j < n - 1) {
                    if(board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == 2)
                        livecell++;
                }
            }
            if(j > 0) {
                if(board[i][j - 1] == 1 || board[i][j - 1] == 2)
                    livecell++;
            }
            if(j < n - 1) {
                if(board[i][j + 1] == 1 || board[i][j + 1] == 2)
                    livecell++;
            }
            if(i < m - 1) {
                if(board[i + 1][j] == 1 || board[i + 1][j] == 2)
                    livecell++;
                if(j > 0) {
                    if(board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == 2)
                        livecell++;
                }
                if(j < n - 1) {
                    if(board[i + 1][j + 1] == 1 || board[i + 1][j + 1] == 2)
                        livecell++;
                }
            }
            if(board[i][j] == 1) {
                if(livecell < 2 || livecell > 3)
                    board[i][j] = 2;
            }
            else if(livecell == 3) {
                board[i][j] = 3;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 2)
                board[i][j] = 0;
            else if(board[i][j] == 3)
                board[i][j] = 1;
        }
    }
}

int main(){}
