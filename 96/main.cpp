#include <iostream>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int numTrees(int n) {
    int **t = new int*[n];
    for (int i = 0; i < n; ++i)
    {
        t[i] = new int[n];
    }
    for (int i = 0; i < n; ++i)
    {
        t[i][i] = 1;
    }
    for (int s = 1; s <= n - 1; ++s)
    {
        for (int i = 0; i < n - s; ++i)
        {
            int j = i + s;
            t[i][j] = t[i + 1][j] + t[i][j - 1];
            for (int k = i + 1; k < j; ++k)
            {
                t[i][j] += t[i][k - 1] * t[k + 1][j];
            }
        }
    }
    return t[0][n - 1];
}

int main() {
    cout<<numTrees(4)<<endl;
    return 0;
}