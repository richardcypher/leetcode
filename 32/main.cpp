#include <iostream>
#include <string>
#include <stack>

using namespace std;

int longestValidParentheses(string s) {
    if(s.empty() || s.length() == 1)
        return 0;
    int* lengths = new int[s.length()];
    lengths[0] = 0;
    for (int i = 1; i < s.length(); ++i)
    {
        if(s[i] == '(')
            lengths[i] = lengths[i - 1];
        else if(s[i] == ')') {
            stack<char> st;
            int length = 0, partlength = 0;
            st.push(')');
            for (int j = i - 1; j >= 0; j--)
            {
                if(s[j] == '(') {
                    if(st.empty())
                        break;
                    st.pop();
                    partlength += 2;
                    if(st.empty()) {
                        length += partlength;
                        partlength = 0;
                    }
                }
                else
                    st.push(')');
            }
            lengths[i] = lengths[i - 1];
            if(lengths[i - 1] < length)
                lengths[i] = length;
        }
    }
    return lengths[s.length() - 1];
}

int main () {
    cout<<longestValidParentheses(")()())()()(")<<endl;
    return 0;
}