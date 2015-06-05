#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(vector<int> perm, int n) {
    for (int i = 0; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if(perm[j] - perm[i] == j - i || perm[j] - perm[i] == i - j)
                return false;
        }
    }
    return true;
}

void NQueens(vector<vector<string> > & result, vector<int>& perm, int index) {
    if(index == perm.size() - 1) {
        if(check(perm, index)) {
            vector<string> r;
            for (int i = 0; i < perm.size(); ++i)
            {
                string str(perm.size(), '.');
                str[perm[i]] = 'Q';
                r.push_back(str);
            }
            result.push_back(r);
        }
    }
    else {
        for (int i = index; i < perm.size(); ++i)
        {
            bool conti = true;
            int tmp = perm[i];
            perm[i] = perm[index];
            perm[index] = tmp;
            if(index > 0 ) {
                if(!check(perm, index))
                    conti  = false;
            }
            if(conti)
                NQueens(result, perm, index + 1);
            tmp = perm[i];
            perm[i] = perm[index];
            perm[index] = tmp;
        }
    }
}

vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > result;
    if(n <= 0)
        return result;
    vector<int> perm;
    for (int i = 0; i < n; ++i)
    {
        perm.push_back(i);
    }
    NQueens(result, perm, 0);
    return result;
}

int main() {
    vector<vector<string> > v = solveNQueens(8);
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            cout<<v[i][j]<<'\t';
        }
        cout<<endl;
    }
    return 0;
}