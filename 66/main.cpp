#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    if(digits.empty())
        return digits;
    int inc = 1;
    for (int i = digits.size() - 1; i >= 0; --i)
    {
        digits[i] += inc;
        if(digits[i] >= 10)
            digits[i] -= 10;
        else {
            inc = 0;
            break;
        }
    }
    if(inc == 1){
        digits.insert(digits.begin(), inc);
    }
    return digits;
}

int main(){
    int arr[] = {9,9,9,9,9};
    vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));
    vector<int> v1 = plusOne(v);
    for (int i = 0; i < v1.size(); ++i)
    {
        cout<<v1[i];
    }
    cout<<endl;
    return 0;
}