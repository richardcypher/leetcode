#include <iostream>

using namespace std;

int removeElement(int A[], int n, int elem) {
    if(n == 0)
        return 0;
    int length = n;
    for (int i = 0; i < n; ++i)
    {
        if(A[i] == elem) {
            while(length - 1 >i && A[length - 1] == elem)
                length--;
            if(length - 1 <= i) {
                length--;
                break;
            }
            A[i] = A[length - 1];
            length--;
        }
        if(i == length - 1)
            break;
    }
    return length;
}

int main() {
    int arr[] = {1};
    int n = removeElement(arr, 1, 1);
    cout<<n<<endl;
    for (int i = 0; i < n; ++i)
    {
        cout<<arr[i]<<'\t';
    }
    cout<<endl;
    return 0;
}