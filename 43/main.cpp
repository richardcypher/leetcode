#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string multiplyHelper(string num, char ch, int bit) {
    string result = "";
    if(ch == '0')
        return "0";
    int inc = 0;
    for (int i = num.length() - 1; i >= 0; --i)
    {
        int bit1 = num[i] - '0',
            bit2 = ch - '0';
        int bitnum = bit1 * bit2 + inc;
        inc = 0;
        while(bitnum >= 10) {
            inc++;
            bitnum -= 10;
        }
        stringstream ss;
        ss<<bitnum;
        result = ss.str() + result;
    }
    if(inc > 0) {
        stringstream ss;
        ss<<inc;
        result = ss.str() + result;
    }
    result.insert(result.end(), bit, '0');
    return result;
}

string add(string num1, string num2) {
    if(num1.empty())
        return num2;
    if(num2.empty())
        return num1;
    int bit = 1, inc = 0;
    string result = "";
    while(bit <= num1.length() && bit <= num2.length()) {
        int bit1 = num1[num1.length() - bit] - '0',
            bit2 = num2[num2.length() - bit] - '0';
        int bitnum = bit1 + bit2 + inc;
        inc = 0;
        if(bitnum >= 10) {
            inc++;
            bitnum -= 10;
        }
        stringstream ss;
        ss<<bitnum;
        result = ss.str() + result;
        bit++;
    }
    string left = "", right = "";
    if(inc > 0) {
        stringstream ss;
        ss<<inc;
        left = ss.str();    
    }
    if(bit <= num2.length()) 
        left = add(left, num2.substr(0, num2.length() - bit + 1));
    if(bit <= num1.length())
        left = add(left, num1.substr(0, num1.length() - bit + 1));
    result = left+ result;
    return result;
}

string multiply(string num1, string num2) {
    if(num1 == "0" || num2 == "0")
        return "0";
    string result;
    int point1 = num1.length(), point2 = num2.length(), point = 0;
    for (int i = 0; i < num1.length(); ++i)
    {
        if(num1[i] == '.')  {
            num1.erase(num1.begin() + i);
            break;
        }
        else
            point1--;
    }
    for (int i = 0; i < num2.length(); ++i)
    {
        if(num2[i] == '.')  {
            num2.erase(num2.begin() + i);
            break;
        }
        else
            point2--;
    }
    point1--;point2--;
    if(point1 > 0)
        point += point1;
    if(point2 > 0)
        point += point2;
    for (int i = num2.length() - 1; i >= 0; i--) 
        result = add(result, multiplyHelper(num1, num2[i], num2.length() - 1 - i));
    if(point != 0)
        result.insert(result.length() - 1 - point, 1, '.');
    return result;
}


int main() {
    cout<<multiply("0","52")<<endl;
    return 0;
}