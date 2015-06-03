#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

vector<string> anagrams(vector<string>& strs) {
    std::vector<string> result;
    std::map<string, int> map;
    for (int i = 0; i < strs.size(); ++i)
    {
        string str = strs[i];
        sort(str.begin(), str.end());
        if(map.find(str) == map.end()) {
            map[str] = i;
        }
        else {
            if(map[str] >= 0) {
                result.push_back(strs[map[str]]);
                map[str] = -1;
            }
            result.push_back(strs[i]);
        }
    }
    return result;
}

int main() {
    string arr[] = {"aab","aba", "afd"};
    std::vector<string> strs(arr, arr + sizeof(arr) / sizeof(arr[0]));
    std::vector<string> v = anagrams(strs);
    for (int i = 0; i < v.size(); ++i)
    {
        cout<<v[i]<<'\t';
    }
    cout<<endl;
    return 0;
}