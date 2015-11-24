/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月24日 星期二 14时45分09秒
 ************************************************************************/

#include<iostream>
#include<sstream>
using namespace std;

string num2str(int a, int b) {
    stringstream ss;
    ss<<a<<"A"<<b<<"B";
    return ss.str();
}

string getHint(string secret, string guess) {
    int bulls = 0, cows = 0;
    int s[10] = {0};
    int i = 0;
    while(i < secret.length()) {
        if(secret[i] == guess[i])
            bulls++;
        else {
            if(s[secret[i] - '0'] < 0) {
                cows++;
            }
            if(s[guess[i] - '0'] > 0) {
                cows++;
            }
            s[secret[i] - '0']++;
            s[guess[i] - '0']--;
        }
        i++;
    }
    return num2str(bulls, cows);
}

int main(){
    cout<<getHint("1123", "0111")<<endl;
}
