#include <iostream>
#include <vector>

using namespace std;

bool check(vector<vector<char> >&board, int row, int col, char item) {
    for (int i = 0; i < 9; ++i)
    {
        if(board[row][i] == item)
            return false;
    }
    for (int i = 0; i < 9; ++i)
    {
        if(board[i][col] == item)
            return false;
    }
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if(board[(row / 3) * 3+ i][(col / 3) * 3 + j] == item)
                return false;
        }
    }
    return true;
}

bool Sudokuhelper(vector<vector<char> >&board, int row, int col) {
    if(row == board.size())
        return true;
    if(board[row][col] != '.') {
        if(col == board.size() - 1)
            return Sudokuhelper(board, row + 1, 0);
        else
            return Sudokuhelper(board, row, col + 1);
    }
    for (int i = 0; i < 9; ++i)
    {
        if(check(board, row, col, '1' + i)) {
            board[row][col] = '1' + i;
            if(col == board.size() - 1 && Sudokuhelper(board, row + 1, 0))
                return true;
            else if(col != board.size() - 1 && Sudokuhelper(board, row, col + 1))
                return true;
            board[row][col] = '.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char> >& board) {
    Sudokuhelper(board, 0, 0);
}

int main() {
    char arr1[] = {'.', '.', '9', '7', '4', '8', '.', '.', '.'};
    char arr2[] = {'7', '.', '.', '.', '.', '.', '.', '.', '.'};
    char arr3[] = {'.', '2', '.', '1', '.', '9', '.', '.', '.'};
    char arr4[] = {'.', '.', '7', '.', '.', '.', '2', '4', '.'};
    char arr5[] = {'.', '6', '4', '.', '1', '.', '5', '9', '.'};
    char arr6[] = {'.', '9', '8', '.', '.', '.', '3', '.', '.'};
    char arr7[] = {'.', '.', '.', '8', '.', '3', '.', '2', '.'};
    char arr8[] = {'.', '.', '.', '.', '.', '.', '.', '.', '6'};
    char arr9[] = {'.', '.', '.', '2', '7', '5', '9', '.', '.'};
    std::vector<char> v1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
    std::vector<char> v2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
    std::vector<char> v3(arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));
    std::vector<char> v4(arr4, arr4 + sizeof(arr4) / sizeof(arr4[0]));
    std::vector<char> v5(arr5, arr5 + sizeof(arr5) / sizeof(arr5[0]));
    std::vector<char> v6(arr6, arr6 + sizeof(arr6) / sizeof(arr6[0]));
    std::vector<char> v7(arr7, arr7 + sizeof(arr7) / sizeof(arr7[0]));
    std::vector<char> v8(arr8, arr8 + sizeof(arr8) / sizeof(arr8[0]));
    std::vector<char> v9(arr9, arr9 + sizeof(arr9) / sizeof(arr9[0]));
    std::vector<std::vector<char> > v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);
    v.push_back(v6);
    v.push_back(v7);
    v.push_back(v8);
    v.push_back(v9);
    solveSudoku(v);
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cout<<v[i][j]<<'\t';
        }
        cout<<endl;
    }
    return 0;
}