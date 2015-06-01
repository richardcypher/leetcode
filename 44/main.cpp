#include <iostream>
#include <string>

using namespace std;
/*
return value:
0 match false
1 match true
-1 cannot find
*/
int matchHelper(string s, string p, int is, int ip) {
    // cout << prefix<<"start@\t" << is << '\t' << ip << endl;
    if (is >= s.length() && ip >= p.length())
        return 1;
    else if (is >= s.length()) {
        while (ip < p.length()) {
            if (p[ip] != '*')
                return 0;
            ip++;
        }
        return 1;
    }
    else if (ip >= p.length())
        return 0;
    else {
        if (p[ip] == '?') {
            return matchHelper(s, p, is + 1, ip + 1);
        }
        else if (p[ip] == '*') {
            while (ip < p.length() - 1 && p[ip + 1] == '*')
                ip++;
            if (ip == p.length() - 1)
                return 1;
            ip++;
            int ip1 = ip;
            int ip2 = p.find('?', ip);
            ip = p.find('*', ip);
            if(ip2 != -1 && (ip2 < ip || ip == -1))
                ip = ip2;
            if (ip == -1)
                ip = p.length();
            string str = p.substr(ip1, ip - ip1);
            // cout << ip1 << "~" << ip << '\t' << str << endl;
            int result = 0;
            do {
                is = s.find(str, is);
                // cout << is << endl;
                if (is == -1)
                    return -1;
                result = matchHelper(s, p, is + str.length(), ip);
                is++;
                if (result == 1)
                    return 1;
                else if(result == -1)
                    return -1;
            } while (is < s.length());
            // cout << "end " << is << endl;
            return 0;
        }
        else {
            if (s[is] == p[ip]) {
                return matchHelper(s, p, is + 1, ip + 1);
            }
            else
                return 0;
        }
    }
}

bool isMatch(string s, string p) {
    // cout << s.length() << '\t' << p.length() << endl;
    return matchHelper(s, p, 0, 0) == 1;
}

int main(){
    cout << isMatch("hi",
        "*?") << endl;
    return 0;
}