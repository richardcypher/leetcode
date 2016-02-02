/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年02月02日 星期二 15时08分17秒
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

bool isValidSerialization(string preorder) {
    stack<string> nodes;
    int i = 0, l = preorder.length();
    string sharp = "#";
    while(i < l) {
        if(preorder[i] == ' ' || preorder[i] == ',') {
            i++;
            continue;
        }
        else if(preorder[i] == '#') {
            if(!nodes.empty()) {
                if(nodes.top() == "#") {
                    while(!nodes.empty() && nodes.top() == "#") {
                        nodes.pop();
                        if(nodes.empty())
                            return false;
                        nodes.pop();
                    }
                }
                nodes.push(sharp);
            }
            else
                nodes.push(sharp);
            i++;
        }
        else {
            while(i < l && preorder[i] != ',' && preorder[i] != ' ')
                i++;
            nodes.push("N");
        }
    }
    return (nodes.size() == 1 && nodes.top() == "#");
}

int main(){
    cout<<isValidSerialization("9,#,#")<<endl;
}
