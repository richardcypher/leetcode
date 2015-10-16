/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月16日 星期五 15时16分46秒
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

void reverseWords(string &s) {
    if(s.empty())
        return;
    int j = 0;
    for(int i = 0; i <= s.length() - 1; i++) {
        if(s[i] != ' ') {
            s[j] = s[i];
            j++;
        }
        else if(i > 0 && s[i - 1] != ' ') {
            s[j] = ' ';
            j++;
        }
    }
    if(j > 0 && s[j - 1] == ' ')
        j--;
    s = s.substr(0, j);
    int begin = 0, end = j- 1;
    while(begin < end) {
        char tmp = s[begin];
        s[begin] = s[end];
        s[end] = tmp;
        begin++;
        end--;
    }
    int it = 0;
    while(it < s.length()) {
        begin = it;
        while(it < s.length() && s[it] != ' ')
            it++;
        end = it;
        end--;
        while(begin < end) {
            char tmp = s[begin];
            s[begin] = s[end];
            s[end] = tmp;
            begin++;
            end--;
        }
        while(it < s.length() && s[it] == ' ')
            it++;
    }
}


int main() {
    string s = " ";
    reverseWords(s);
    cout<<s<<endl;
    return 0;
}
