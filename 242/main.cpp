/********.*****************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月18日 星期三 10时58分38秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

/*
bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        int a[26]={0};
        for(int i=0;i<s.length();++i ){
            a[s[i]-'a']++;
            a[t[i]-'a']--;
        }
        for(int i=0;i<26;++i)
            if(a[i]!=0)
                return false;
       return true;
    }
*/

bool isAnagram(string s, string t) {
    if(s.length() != t.length())
        return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

int main() {
    
}
