#include <iostream>
#include <string>
using namespace std;

int romanToInt(string s) {
    int index = s.length() - 1;
    bool add = true;
    int result = 0;
    while(index != -1) {
        int unit_num = 0;
        switch(s[index]) {
            case 'I':
                unit_num = 1;
                break;
            case 'V':
                unit_num = 5;
                break;
            case 'X':
                unit_num = 10;
                break;
            case 'L':
                unit_num = 50;
                break;
            case 'C': 
                unit_num = 100;
                break;
            case 'D':
                unit_num = 500;
                break;
            case 'M':
                unit_num = 1000;
                break;
        }
        if(add) {
            result += unit_num;
        }
        else {
            result -= unit_num;
            add = true;
        }
        if(index != 0 && (
            (s[index - 1] == 'I' && (s[index] == 'V' || s[index] == 'X') )|| 
            (s[index - 1] == 'X' && (s[index] == 'L' || s[index] == 'C') )|| 
            (s[index - 1] == 'C' && (s[index] == 'D' || s[index] == 'M')) )) {
            add = false;
        }
        index--;
    }
    return result;
}

int main() {
    cout<<romanToInt("CXCIX")<<endl;
    return 0;
}