#include <iostream>
using namespace std;

int divide(int dividend, int divisor) {
    if(divisor == 0)
        return 2147483647;
    if(dividend == 0)
        return 0;
    bool positive = false;
    if((dividend < 0 && divisor < 0) || (dividend> 0 && divisor > 0))
        positive = true;
    int quotient = 0;
    if(divisor == -2147483648ll && dividend == -2147483648ll)
        return 1;
    else if(divisor == -2147483648ll)
        return 0;
    else if(dividend == -2147483648ll) {
        if(divisor > 0) {
            quotient += 1;
            dividend += divisor;
        }
        else if(divisor == -1) {
            return 2147483647;
        }
        else {
            quotient += 1;
            dividend -= divisor;
        }
    }
    if(dividend < 0)
        dividend = 0 - dividend;
    if (divisor < 0)
        divisor = 0 - divisor;
    while(divisor<= dividend) {
        int timesof2 = 1;
        int tmp = divisor;

        while (tmp <= dividend - tmp) {
            timesof2 += timesof2;
            tmp += tmp;
        }
        quotient += timesof2;
        dividend -= tmp;
    }
    quotient = positive ? quotient : (0 - quotient);
    return quotient;
}

int main() {
    cout<<divide(-2147483648ll,-1)<<endl;
    return 0;
}