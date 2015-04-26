#include <iostream>

using namespace std;
int removeDuplicates(int A[], int n) {
    if(n <= 1)
        return n;
    int j = 1;
    for (int i = 1; i < n; ++i)
    {
        if(A[i] != A[i - 1]) {
            A[j] = A[i];
            j++;
        }
    }
    return j;
}
int main() {
    int arr[] = {1,1,2,3,3};
    int n = removeDuplicates(arr, 5);
    for (int i = 0; i < n; ++i)
    {
        cout<<arr[i]<<'\t';
    }
    cout<<endl;
    return 0;
}