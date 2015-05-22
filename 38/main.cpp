#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string countAndSay(int n) {
    if(n <= 0)
        return "";
    else if(n == 1)
        return "1";
    string str = countAndSay(n - 1);
    string result = "";
    char ch = str[0];
    int count = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        if(str[i] == ch)
            count++;
        else {
            stringstream ss;
            ss<<count;
            result += ss.str() + ch;
            count = 1;
            ch = str[i];
        }
    }
    stringstream ss;
    ss<<count;
    result += ss.str() + ch;
    return result;
}

int main() {
    cout<<countAndSay(5)<<endl;
    return 0;
}