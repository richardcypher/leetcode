#include <iostream>

using namespace std;

int climbStairs(int n) {
    if(n <= 0)
        return 0;
    int *arr = new int[n];
    arr[0] = 1;arr[1] = 2;
    for (int i = 2; i < n; ++i)
    {
        arr[i] = arr[i - 1] + arr[ i - 2];
    }
    return arr[n - 1];
}

int main() {
    cout<<climbStairs(3)<<endl;
    return 0;
}