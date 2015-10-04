#include <iostream>
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

int main()  {
    return 0;
}