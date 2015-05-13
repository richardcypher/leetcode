#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char> >& board) {
    bool nums[9] = {false};
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if(board[i][j] == '.')
                continue;
            else if(board[i][j] <= '9' && board[i][j] >= '1') {
                if(!nums[board[i][j] - '1']) 
                    nums[board[i][j] - '1'] = true;
                else
                    return false;
            }
            else
                return false;
        }
        for (int i = 0; i < 9; ++i)
            nums[i] = false;
    }
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if(board[j][i] == '.')
                continue;
            else if(board[j][i] <= '9' && board[j][i] >= '1') {
                if(!nums[board[j][i] - '1'])
                    nums[board[j][i] - '1'] = true;
                else
                    return false;
            }
            else
                return false;
        }
        for (int i = 0; i < 9; ++i)
            nums[i] = false;
    }
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k1 = 0; k1 < 3; ++k1)
            {
                for (int k2 = 0; k2 < 3; ++k2)
                {
                    if(board[i * 3 + k1][j * 3 + k2] == '.')
                        continue;
                    else if(board[i * 3 + k1][j * 3 + k2] <= '9' && board[i * 3 + k1][j * 3 + k2] >= '1' ) {
                        if(!nums[board[i * 3 + k1][j * 3 + k2] - '1'])
                            nums[board[i * 3 + k1][j * 3 + k2] - '1'] = true;
                        else 
                            return false;
                    }
                    else
                        return false;
                }
            }
            for (int i = 0; i < 9; ++i)
                nums[i] = false;
        }
    }
    return true;
}

int main() {
    char arr1[] = {'.', '8', '7', '6', '5', '4', '3', '2', '1'};
    char arr2[] = {'2', '.', '.', '.', '.', '.', '.', '.', '.'};
    char arr3[] = {'3', '.', '.', '.', '.', '.', '.', '.', '.'};
    char arr4[] = {'4', '.', '.', '.', '.', '.', '.', '.', '.'};
    char arr5[] = {'5', '.', '.', '.', '.', '.', '.', '.', '.'};
    char arr6[] = {'6', '.', '.', '.', '.', '.', '.', '.', '.'};
    char arr7[] = {'7', '.', '.', '.', '.', '.', '.', '.', '.'};
    char arr8[] = {'8', '.', '.', '.', '.', '.', '.', '.', '.'};
    char arr9[] = {'9', '.', '.', '.', '.', '.', '.', '.', '.'};
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
    cout<<isValidSudoku(v)<<endl;
    return 0;
}