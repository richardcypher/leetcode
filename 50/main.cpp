#include <iostream>

using namespace std;

double myPow(double x, int n) {
    if(x == 0)
        return 0;
    if(n == 0)
        return 1;
    else if(n == 1)
        return x;
    else if(n == -1)
        return 1 / x;
    double r = myPow(x, n / 2);
    if(n % 2 == 0)
        return r * r;
    else if(n > 0)
        return r * r * x;
    else if(n < 0)
        return r * r * (1 / x);
}

int main() {
    cout<<myPow(34.00515, -3)<<endl;
    return 0;
}