#include <iostream>
#include <string>
using namespace std;

string convert(string s, int nRows) {
    if(nRows < 1)
        return "";
    else if(nRows == 1)
        return s;
    string result = "";
    for(int i = 0; i < nRows; i++) {
        int n = i;
        while(n < s.length()){
            result += s[n];
            n += 2 * (nRows - i - 1);
            if(n >= s.length())
                break;
            if( i != 0 && i != nRows - 1)
                result += s[n];
            n += 2 * i;
        }
    }
    return result;
}

int main() {
    string str = convert("PAYPALISHIRING", 3);
    cout<<str<<endl;
    return 0;
}