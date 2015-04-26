#include <iostream>
using namespace std;

bool isMatch(const char *s, const char *p) {
    if(s[0] == '\0' && p[0] == '\0')
        return true;
    else if(s[0] == '\0') {
        if(p[1] == '\0')
          return false;
      else if(p[1] != '*')
          return false;
      p++;
      p++;
      return isMatch(s, p);
    }
    else if(p[0] == '\0') {
        return false;
    }
    else {
        if(p[1] == '*') {
            const char* tmpp = p, *tmps = s;
            tmpp += 2;
            if(isMatch(tmps, tmpp ))
                return true;
            if(s[0] == p[0]  || p[0] == '.') {
                s++;
                return isMatch(s, p);
            }
            else {
                return false;
            }
        }
        else {
          if(s[0] == p[0] || p[0] == '.') {
            s++;
            p++;
            return isMatch(s, p);
        }
        else
            return false;
        }
    }
}

int main() {
    cout<<boolalpha<<isMatch("aaaaabaccbbccababa","a*b*.*c*c*.*.*.*c")<<endl;
    return 0;
}
