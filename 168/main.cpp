/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月18日 星期日 14时14分09秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

string converToTitle(int n) {
    string str = "";
    char ch;
    n--;
    while(n > 0) {
        ch = 'A' + n % 26;
        str = ch + str;
        n = n / 26;
    }
    if(n == 0)
    {
        str = "A" + str;
    }
    return str;
}

int main() {
    cout<<converToTitle(123)<<endl;
    return 0;
}
