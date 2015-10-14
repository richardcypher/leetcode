#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

bool wordBreak(string s, unordered_set<string>& wordDict) {
    if(s.empty())
        return false;
    bool* breaks = new bool[s.length()];
    breaks[0] = !(wordDict.find(s.substr(0,1)) == wordDict.end());
    for(int i = 1; i < s.length(); i++) {
        breaks[i] = false;
        if(wordDict.find(s.substr(0, i + 1)) != wordDict.end()) {
            breaks[i] = true;
            continue;
        }
        for(int j = 0; j < i; j++) {
            if(breaks[j] && wordDict.find(s.substr(j + 1, i - j)) != wordDict.end())
               breaks[i] = true;
        }
    }
    return breaks[s.length() - 1];
}

int main() {
    return 0;
}
