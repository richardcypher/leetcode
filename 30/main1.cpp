#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>    

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    std::vector<int> result;
    if(s.empty() || words.empty())
        return result;
    std::map<string, int> wordrepeat;
    int wordlength = words[0].length();
    if(words.size() * wordlength > s.length())
        return result;
    for (int i = 0; i < words.size(); ++i)
    {
        if(wordrepeat.find(words[i]) != wordrepeat.end())
            continue;
        wordrepeat[words[i]] = std::count(words.begin(), words.end(), words[i]);
    }
    for (int i = 0; i < wordlength; ++i)
    {
        int startpos = i, count = 0;
        std::map<string, int> wordcount;
        for (int j = i; j <= s.length() - wordlength; j += wordlength)
        {
            string str = s.substr(j, wordlength);
            if(wordrepeat.find(str) != wordrepeat.end()) {
                wordcount[str]++;
                if(wordcount[str] <= wordrepeat[str])
                    count++;
                else {
                    while(wordcount[str] > wordrepeat[str]) {
                        string str1 = s.substr(startpos, wordlength);
                        wordcount[str1]--;
                       if(wordcount[str1] < wordrepeat[str1])
                            count--;
                        startpos += wordlength;
                    }
                }
            }
            else {
                startpos = j + wordlength;
                count = 0;
                wordcount.clear();
            }

            if(count == words.size()) {
                result.push_back(startpos);
                string str = s.substr(startpos, wordlength);
                wordcount[str]--;
                count--;
                startpos += wordlength;
            }
        }
    }
    return result;
};

int main () {
    string wds[] = {"foo","bar"};
    std::vector<string> words(wds, wds + sizeof(wds) / sizeof(wds[0]));
    std::vector<int> v = findSubstring("barfoothefoobarman",words);
    for (int i = 0; i < v.size(); ++i)
    {
        cout<<v[i]<<'\t';
    }
    cout<<endl;
    return 0;
}