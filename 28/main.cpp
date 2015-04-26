#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle) {
    if(needle.length() > haystack.length())
        return -1;
    else if(needle == "")
        return 0;
    for (int i = 0; i < haystack.length() - needle.length() + 1; ++i)
    {
        if(haystack[i] == needle[0]) {
            int needle_i =0;
            while(needle_i < needle.length()) {
                if(haystack[i + needle_i] != needle[needle_i])
                    break;
                else if(needle_i == needle.length() - 1)
                    return i;
                needle_i++;
            }
        }
    }
    return -1;
}
int main() {
    int index = strStr("abcaab","aac");
    cout<<index<<endl;
    return 0;
}