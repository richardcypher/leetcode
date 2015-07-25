#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> restoreHelper(string s, int index, int part) {
    vector<string> result;
    if(s.empty() || index >= s.length() || part > s.length())
        return result;
    if(index <= s.length() - 1  && index >= s.length() - 3 && part == 1) {
        if(index == s.length() - 3) {
            if(s[index] == '1' || (s[index] == '2' && (s[index + 1] < '5' || (s[index + 1] == '5' && s[index + 2] <= '5')))) {
                result.push_back(s.substr(index));
            }
        }
        else if(index == s.length() - 2 && s[index] != '0')
            result.push_back(s.substr(index));
        else if(index == s.length() - 1)
            result.push_back(s.substr(index));
        return result;
    }
    vector<string> bit1 = restoreHelper(s, index + 1, part - 1);
    for (int i = 0; i < bit1.size(); ++i)
    {
        bit1[i] = s.substr(index, 1) + "." + bit1[i];
        result.push_back(bit1[i]);
    }
    if(s[index] != '0') {
        vector<string> bit2 = restoreHelper(s, index + 2, part - 1);
        for (int i = 0; i < bit2.size(); ++i)
        {
            bit2[i] = s.substr(index, 2) + "." + bit2[i];
            result.push_back(bit2[i]);
        }
    }
    if(index <= s.length() - 3 && s[index] != '0') {
        if(s[index] == '1' || (s[index] == '2' && (s[index + 1] < '5' || (s[index + 1] == '5' && s[index + 2] <= '5')))) {
            vector<string> bit3 = restoreHelper(s, index + 3, part - 1);
            for (int i = 0; i < bit3.size(); ++i)
            {
                bit3[i] = s.substr(index, 3) + "." + bit3[i];
                result.push_back(bit3[i]);
            }
        }
    }
    return result;
}

vector<string> restoreIpAddresses(string s) {
    return restoreHelper(s, 0, 4);
}

int main() {
    vector<string> v = restoreIpAddresses("00000");
    for (int i = 0; i < v.size(); ++i)
    {
        cout<<v[i]<<'\t';
    }
    cout<<endl;
    return 0;
}