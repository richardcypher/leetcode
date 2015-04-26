#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs) {
    if(strs.size() == 0)
        return "";
    string prefix = "";
    int length = 0;
    bool goon = true;
    while(goon) {
        char ch = ' ';
        for(std::vector<string>::iterator it = strs.begin(); it != strs.end(); it++)
        {
            if((*it).length() == length){
                goon = false;
                break;
            }
            if(it == strs.begin())
            {
                ch = (*it)[length];
            }
            else
            {
                if(ch != (*it)[length])
                    goon = false;
            }
        }
        if(goon) {
            prefix += ch;
            length++;
        }
    }
    return prefix;
}

int main() {
    std::vector<string> v;
    cout<<longestCommonPrefix(v)<<endl;
    return 0;
}