/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月27日 星期二 16时43分23秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<string>
using namespace std;

bool isIsomorphic(string s, string t) {
    if(s.empty() || t.empty())
        return true;
    map<char, char> mp;
    map<char, bool> m;
    int i = 0, l = s.length();
    while(i < l) {
        if(mp.find(s[i]) != mp.end()) {
            if(mp[s[i]] != t[i])
                return false;
        }
        else {
            if(m.find(t[i]) != m.end())
                return false;
            mp[s[i]] = t[i];
            m[t[i]] = true;
        }
        i++;
    }
    return true;
}

int main() {
    return 0;
}
