#include <iostream>
#include <string>

using namespace std;

int minDistance(string word1, string word2) {
    if(word1.empty())
        return word2.length();
    if(word2.empty())
        return word1.length();
    int m = word1.length() + 1, n = word2.length() + 1;
    int** arr = new int*[m];
    for (int i = 0; i < m; ++i)
    {
        arr[i] = new int[n];
    }
    for (int i = 0; i < m; ++i)
    {
        arr[i][0] = i;
    }
    for (int i = 0; i < n; ++i)
    {
        arr[0][i] = i;
    }
    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            arr[i][j] = 1 + arr[i - 1][j];
            if(arr[i][j] > 1 + arr[i][j - 1])
                arr[i][j] = 1 + arr[i][j - 1];
            int dis = 1;
            if(word1[i - 1] == word2[j - 1])
                dis = 0;
            dis += arr[i - 1][j - 1];
            if(arr[i][j] > dis)
                arr[i][j] = dis;
        }
    }
    return arr[m - 1][n - 1];
}

int main() {
    cout<<minDistance("a","b")<<endl;
    return 0;
}