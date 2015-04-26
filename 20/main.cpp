#include <iostream>
#include <string>
#include <stack>

using namespace std;
bool isValid(string s) {
    stack<char> st;
    if(s.empty())
        return false;
    if(s[0] == '}' || s[0] == ']' || s[0] == ')')
        return false;
    st.push(s[0]);
    int i = 1;
    while(!st.empty() || i < s.length())
    {
        if(i >= s.length())
            return false;
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]);
        else if(s[i] == ')')
        {
            if(!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
                return false;
        }
        else if(s[i] == ']')
        {
            if(!st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
                return false;
        }
        else if(s[i] == '}')
        {
            if(!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
                return false;
        }
        i++;
    }
    return true;
}
int main() {
    cout<<boolalpha<<isValid("[])")<<endl;
    return 0;
}