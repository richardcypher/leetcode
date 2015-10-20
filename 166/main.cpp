/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月18日 星期日 14时10分28秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<sstream>
#include<map>
using namespace std;

string num2str(long long num) {
    stringstream ss;
    ss<<num;
    return ss.str();
}

string fractionToDecimal(int numerator, int denominator) {
    string str = "";
    if(denominator == 0)
        return str;
    bool pos = false;
    if((numerator >= 0 && denominator > 0) || (numerator <= 0 && denominator < 0))
        pos = true;
    long long numerator1 = numerator, denominator1 = denominator;
    if(numerator1 < 0)
        numerator1 *= -1;
    if(denominator1 < 0)
        denominator1 *= -1;
    if(numerator1 % denominator1 == 0)
    {
        long long num = numerator1 / denominator1;
        str = num2str(num); 
        if(!pos)
            str = "-" + str;
       return str;
    }
    map<long, int> lefts;
    str = num2str(numerator1 / denominator1);
    str += ".";
    long  long left = numerator1 % denominator1;
    int divided;
    while(left != 0) {
        left *= 10;
        if(lefts.find(left) != lefts.end()) {
            str = str.substr(0, lefts[left]) + "(" + str.substr(lefts[left]) + ")";
            break;
        }
        divided = left / denominator1;
        str += num2str(divided);
        lefts[left] = str.length() - 1;
        left = left % denominator1;
    }
    if (!pos)
        str = "-" + str;
    return str;
}

int main() {
    cout<<fractionToDecimal(7, -12)<<endl;
    return 0;
}
