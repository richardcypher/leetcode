#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;
int atoi(string str) {
    if(str == "")
        return 0;
    int start = 0, end =0;
    bool neg = false;
    while(str[start] == '0' || str[start] == ' ')
        start ++;
    if(str[start] == '-') {
        start ++;
        neg = true;
    }
    else if(str[start] == '+')
        start++;
    else if(str[start] < '0' || str[start] > '9')
        return 0;
    if(start == str.length())
        return 0;

    end = start;
    while(end < str.length() && str[end] >= '0' && str[end] <= '9')
        end++;
    str = str.substr(start,end - start);
    int bits = str.length();
    if(bits > 10){
        if(neg)
            return -2147483648ll;
        else
            return 2147483647;
    }
    int result = 0;
    for(int j = bits - 1; j >= 0; j--) {
        int bit = str[bits - 1 -j] - '0';
        long long addnum = bit * pow(10.0, j) * 1.0;
        if(!neg && 2147483647 - addnum <= result){
            return 2147483647;
        }
        if(neg && 2147483648ll - addnum <= result) {
            return -2147483648ll;
        }
        result += addnum;
    }
    if(neg)
        result *= - 1;

    return result;
    }
int main() {
    cout<<atoi("      -11919730356x")<<endl;
    return 0;
 }