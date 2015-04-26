#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;
int reverse(int x) {
    bool neg = false;
    if(x < 0) {
        if(x == -2147483648ll)
            return 0;
        neg = true;
        x *= -1;
    }
    string num = "";
    int bits = 0;
    int result = 0;
    while(x != 0) {
        int i = x %10;
        ostringstream os;
        os << i;
        num += os.str();
        x /= 10;
    }
    int start = 0;
    while(num[start] == '0')
        start ++;
    num = num.substr(start);
    bits = num.length();
    for(int j = bits - 1; j >= 0; j--) {
        int bit = num[bits - 1 -j] - '0';
        int addnum = bit * pow(10.0, j) * 1.0;
        if(!neg && 2147483647 - addnum <= result){
            return 0;
        }
        if(neg && 2147483648ll - addnum <= result) {
            return 0;
        }
        result += addnum;
    }
    if(neg)
        result *= - 1;

    return result;
    }
int main() {
    cout<<reverse(-2147483648ll)<<endl;
    return 0;
 }