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

void NQueens(int &total, vector<int>& perm, int index) {
    if(index == perm.size() - 1) {
        if(check(perm, index)) {
            total++;
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
                NQueens(total, perm, index + 1);
            tmp = perm[i];
            perm[i] = perm[index];
            perm[index] = tmp;
        }
    }
}

int totalNQueens(int n) {
    int total = 0;
    if(n <= 0)
        return 0;
    vector<int> perm;
    for (int i = 0; i < n; ++i)
    {
        perm.push_back(i);
    }
    NQueens(total, perm, 0);
    return total;
}

int main() {
    int n = totalNQueens(8);
    cout<<n<<endl;
    return 0;
}