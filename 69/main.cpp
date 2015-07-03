#include <iostream>
using namespace std;
int mySqrt(int x) {
    if(x <= 0)
        return 0;
    int low = 1, high = x, mid = (x + 1) / 2;
    while(mid  != x / mid && low <= high) {
        if(mid < x / mid) {
            low = mid + 1;
        }
        else if(mid > x / mid) {
            high = mid - 1;
        }
        else
            return mid;
        mid = (low + high) / 2;
    }
    return mid;
}
int main() {
    cout<<mySqrt(8)<<endl;
    return 0;
}