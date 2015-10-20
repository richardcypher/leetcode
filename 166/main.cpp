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

string num2str(long num) {
    stringstream ss;
    ss<<num;
    return ss.str();
}

string fractionToDecimal(int numerator, int denominator) {
    string str = "";
    if(numerator == -2147483648 && denominator == -1)
        return "2147483648";
    if(numerator % denominator == 0)
    {
       return num2str(numerator / denominator); 
    }
    else if(numerator > denominator) {
        map<int, int> lefts;
        str = num2str(numerator / denominator);
        str += ".";
        int left = numerator % denominator;
        int divided;
        while(left != 0) {
            left *= 10;
            if(lefts.find(left) != lefts.end()) {
                str = str.substr(0, lefts[left]) + "(" + str.substr(lefts[left]) + ")";
                return str;
            }
            divided = left / denominator;
            str += num2str(divided);
            lefts[left] = str.length() - 1;
            left = left % denominator;
        }
    }
    else if(numerator < denominator) {
        str = "0.";
        int left = numerator * 10;
        string ss = "";
        while(left < denominator) {
            left *= 10;
            ss += "0";
        }
        string lnum, rnum;
        string dividedstr = fractionToDecimal(left, denominator);
        dividedstr = ss + dividedstr;
        for(int i = 0;i < dividedstr.length(); i++) {
            if(dividedstr[i] == '.') {
                lnum = lnum + dividedstr.substr(0, i);
                dividedstr.erase(i, 1);
                break;
            }
        }
        size_t l = dividedstr.find_first_of("(");
        if(l != string::npos) {
            rnum = dividedstr.substr(l + 1);
            rnum.erase(rnum.length() - 1);
            if(l == lnum.length()) {
                int lastl = l - 1, lastr = rnum.length() - 1;
                int move = 0;
                while(lastl >= 0 && lastr >= 0 && lnum[lastl] == rnum[lastr])
                {
                    lastl--;
                    lastr--;
                    move++;
                }
                for(int i = 0; i < move; i++)
                    dividedstr[l - i] = dividedstr[l - i - 1];
                dividedstr[l - move] = '(';
                dividedstr[dividedstr.length() - 1 - move] = ')';
                dividedstr.erase(dividedstr.length() - move);
            }
        }
        str += dividedstr;
    }
    return str;
}

int main() {
    cout<<fractionToDecimal(1, 99)<<endl;
    return 0;
}
