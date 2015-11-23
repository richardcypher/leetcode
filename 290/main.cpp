/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月23日 星期一 18时19分01秒
 ************************************************************************/

#include<iostream>
#include<sstream>
#include<map>
using namespace std;

bool wordPattern(string pattern, string str) {
    int i = 0, lp = pattern.length();
    map<char, string> mp;
    map<string, char> exist;
    istringstream iss(str);
    do {
        string sub;
        iss>>sub;
        if(i > lp)
            return false;
        if(i < lp) {
            if(mp.count(pattern[i]) == 0) {
                if(exist.count(sub) != 0)
                    return false;
                mp[pattern[i]] = sub;
                exist[sub] = pattern[i];
            }
            else {
                if(mp[pattern[i]] != sub)
                    return false;
            }
        }
        i++;
    } while(iss);
    return i == lp + 1;
}

int main() {
    cout<<wordPattern("abba", "dog dog dog dog")<<endl;
}
