#include <iostream>
#include <string>
using namespace std;

string addBinary(string a, string b) {
    string r = "";
    while(a.length() < b.length())
        a = "0" + a;
    while(b.length() < a.length())
        b = "0" + b;
    int m = a.length();
    int pos = 0;
    bool inc = false;
    while(m - 1 - pos >= 0) {
        string s = "";
        if(inc)
            s = "1";
        if(a[m - 1 - pos] == b[m - 1- pos])
            s = s == "1" ? "1" :"0";
        else
            s = s == "1" ? "0" :"1";
        r = s + r;
        if(!inc) {
            if(a[m - 1 - pos] == '1' && b[m - 1 - pos] == '1')
                inc = true;
            else
                inc = false;
        }
        else {
            if(a[m - 1 - pos] == '1' || b[m - 1 - pos] == '1')
                inc = true;
            else
                inc = false;
        }
        pos++;
    }
    if(inc)
        r = "1" + r;
    return r;
}

int main() {
    cout<<addBinary("1", "11")<<endl;
    return 0;
}