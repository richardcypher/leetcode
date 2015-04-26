#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    std::vector<int> result;
    if(s.empty() || words.empty())
        return result;
    std::vector<std::vector<int> > wordsindex;
    for (int i = 0; i < words.size(); ++i)
    {
        std::vector<int> index;
        int pos = s.find(words[i], 0);
        while(pos != string::npos) {
            index.push_back(pos);
            pos = s.find(words[i], pos + 1);
        }
        if(index.empty())
            return result;
        wordsindex.push_back(index);
    }
    int wordlength = words[0].length();
    int wordscount = words.size();
    while(true) {
        bool* wordappear = new bool[wordscount];
        int minindex = 0;
        for (int i = 0; i < wordscount; ++i)
        {
            wordappear[i] = false;
            if(wordsindex[i].empty())
                return result;
            if(wordsindex[i][0] < wordsindex[minindex][0])
                minindex = i;
        }

        int startindex = wordsindex[minindex][0];
        int endindex = startindex + (wordscount - 1) * wordlength;
        wordappear[minindex] = true;
        int wordsfound = 1;
        for (int i = 0; i < wordscount; ++i)
        {
            if(wordsindex[i][0] >= startindex && wordsindex[i][0] <= endindex && !wordappear[i]) {
                wordappear[i] = true;
                wordsfound++;
            }
        }
        if(wordsfound == wordscount) {
            result.push_back(wordsindex[minindex][0]);
        }
        wordsindex[minindex].erase(wordsindex[minindex].begin());
        delete[] wordappear;
    }
    return result;
};

int main () {
    string wds[] = {"foo", "man"};
    std::vector<string> words(wds, wds + sizeof(wds) / sizeof(wds[0]));
    std::vector<int> v = findSubstring("barfoothefoobarman",words);
    for (int i = 0; i < v.size(); ++i)
    {
        cout<<v[i]<<'\t';
    }
    cout<<endl;
    return 0;
}