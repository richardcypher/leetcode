#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) {
    int lastlen = 0, i = 0;
    while(i < s.length()) {
        while(i < s.length() && s[i] == ' ')
            i++;
        if(i == s.length())
            return lastlen;
        int curlen = 0;
        while(i < s.length() && s[i] != ' ') {
            i++;
            curlen++;
        }
        lastlen = curlen;
    }
    return lastlen;
}

int main(){
    cout<<lengthOfLastWord("Hello World   ")<<endl;
    return 0;
}
