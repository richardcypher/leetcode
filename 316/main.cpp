#include<iostream>
#include<algorithm>

using namespace std;


string removeDuplicateLetters(string s){
    if(s.empty())
        return "";
    int cnt[26] = {0};
    int pos = 0;
    for(int i = 0; i < s.length(); i++)
        cnt[s[i] - 'a']++;
    for(int i = 0; i < s.length(); i++){
        if(s[i] < s[pos])
            pos = i;
        if(--cnt[s[i] - 'a'] == 0)
            break;
    }
    string str = "";
    string result = "a";
    result[0] = s[pos];
    if(pos < s.length() - 1) {
        str = s.substr(pos + 1);
        str.erase(std::remove(str.begin(), str.end(), s[pos]), str.end());
       result += removeDuplicateLetters(str);
    }
    return result;
}

int main(){
    cout<<removeDuplicateLetters("bcabc")<<endl;
}
