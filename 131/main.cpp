#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(string s) {
    if(s.empty())
        return true;
    int low = 0, high = s.length() - 1;
    while(low < high) {
        while(low < s.length() && !((s[low] >= 'a' && s[low] <= 'z') ||(s[low] >= 'A' && s[low] <= 'Z') || (s[low] >= '0' && s[low] <= '9')))
            low++;
        while(high >= 0 && !((s[high] >= 'a' && s[high] <= 'z') ||(s[high] >= 'A' && s[high] <= 'Z') || (s[high] >= '0' && s[high] <= '9')))
            high--;
        if(low >= high)
            break;
        if(s[low] >= 'A' && s[low] <= 'Z')
            s[low] = s[low] - ('A' - 'a');
        if(s[high] >= 'A' && s[high] <= 'Z')
            s[high] = s[high] - ('A' - 'a');
        if(s[low] != s[high])
            return false;
        low++;
        high--;
    }
    return true;
}

vector<vector<string> > subset(string s, int num) {
    vector<vector<string> > result;
    if(num == 0)
    {
        if(!isPalindrome(s))
            return result;
        vector<string> set;
        set.push_back(s);
        result.push_back(set);
        return result;
    }
    if(num > s.length() - 1)
        return result;
    for (int i = 1; i <= s.length() - num ; ++i)
    {
        string str = s.substr(0, i);
        if(!isPalindrome(str))
            continue;
        vector<vector<string> > sets = subset(s.substr(i), num - 1);
        for (int j = 0; j < sets.size(); ++j)
        {
            sets[j].insert(sets[j].begin(), str);
            result.push_back(sets[j]);
        }
    }
    return result;
}

vector<vector<string> > partition(string s) {
    vector<vector<string> > result;
    if(s.empty())
        return result;
    for (int i = 0; i < s.length(); ++i)
    {
        vector<vector<string> > sets = subset(s, i);
        for (int j = 0; j < sets.size(); ++j)
        {
            result.push_back(sets[j]);
        }
    }
    return result;
}
/*
public List<List<String>> partition(String s) {
    List<List<String>> ans = new ArrayList<>();
    partition(ans, new ArrayList<String>(), s, 0);
    return ans;
}

private void partition(List<List<String>> ans, ArrayList<String> part,
        String s, int start) {
    if (start == s.length()) {
        List<String> li = new ArrayList<>(part);
        ans.add(li);
    }
    for (int i = start; i < s.length(); i++) {
        if (isParlindrome(s.substring(start, i+1))){
            part.add(s.substring(start, i+1));
            partition(ans, part, s, i+1);
            part.remove(part.size() - 1);
        }
    }
}
*/

int main() {
    vector<vector<string> > result = partition("kwtbjmsjvbrwriqwxadwnufplszhqccayvdhhvscxjaqsrmrrqngmuvxnugdzjfxeihogzsdjtvdmkudckjoggltcuybddbjoizu");
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
        {
            cout<<result[i][j]<<'\t';
        }
        cout<<endl;
    }
    return 0;
}