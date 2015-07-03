#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

string simplifyPath(string path) {
    stack<string> pathst;
    stringstream ss(path);
    string item;
    while(getline(ss, item, '/')) {
        if(!item.empty()) {
            if(item == ".")
                continue;
            else if(item == "..") {
                if(!pathst.empty())
                    pathst.pop();
                continue;
            }
            pathst.push(item);
        }
    }
    if(pathst.empty())
        return "/";
    string p = "";
    while(!pathst.empty()) {
        p = "/" + pathst.top() + p;
        pathst.pop();
    }
    return p;
}

int main() {
    cout<<simplifyPath("/..")<<endl;
    return 0;
}