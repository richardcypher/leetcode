#include <iostream>
#include <string>

using namespace std;

int numDecodings(string s) {
    if(s.empty())
        return 0;
    int n = s.length();
    int* arr = new int[n + 1];
    if(s[0] <= '0' || s[0] > '9')
        return 0;
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        arr[i] = 0;
        if(arr[i - 1] != 0 && s[i - 1] >= '1' && s[i - 1] <= '9')
            arr[i] = arr[i - 1];
        if(i == 2 || arr[i - 2] != 0) {
            if(s[i - 2] == '1' && s[i - 1] >= '0' && s[i - 1] <= '9') {
                arr[i] += arr[i - 2];
            }
            else if(s[i - 2] == '2' && s[i - 1] >= '0' && s[i - 1] <= '6') {
                arr[i] += arr[i - 2];
            }
        }
        if(arr[i] == 0)
            return 0;
    }
    return arr[n];
}

int main() {
    cout<<numDecodings("10")<<endl;
    return 0;
}