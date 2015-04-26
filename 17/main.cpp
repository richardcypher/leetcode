#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> letterCombinations(string digits) {
    std::vector<string> v,tmp;
    if(digits == "")
        return v;
    string substr = "";
    if(digits.length() > 1)
        substr = digits.substr(1);
    tmp = letterCombinations(substr);
    switch(digits[0])
    {
        case '0':
            if(tmp.size() == 0)
                v.push_back(" ");
            for(std::vector<string>::iterator it = tmp.begin(); it != tmp.end(); it++)
            {
                v.push_back(" " + *it);
            }
            break;
        case '1':
            return tmp;
        case '2':
            if(tmp.size() == 0)
            {
                v.push_back("a");
                v.push_back("b");
                v.push_back("c");
            }
            for(std::vector<string>::iterator it = tmp.begin(); it != tmp.end(); it++)
            {
                v.push_back("a" + *it);
                v.push_back("b" + *it);
                v.push_back("c" + *it);
            }
            break;
        case '3':
            if(tmp.size() == 0)
            {
                v.push_back("d");
                v.push_back("e");
                v.push_back("f");
            }
            for(std::vector<string>::iterator it = tmp.begin(); it != tmp.end(); it++)
            {
                v.push_back("d" + *it);
                v.push_back("e" + *it);
                v.push_back("f" + *it);
            }
            break;
        case '4':
            if(tmp.size() == 0)
            {
                v.push_back("g");
                v.push_back("h");
                v.push_back("i");
            }
            for(std::vector<string>::iterator it = tmp.begin(); it != tmp.end(); it++)
            {
                v.push_back("g" + *it);
                v.push_back("h" + *it);
                v.push_back("i" + *it);
            }
            break;
        case '5':
            if(tmp.size() == 0)
            {
                v.push_back("j");
                v.push_back("k");
                v.push_back("l");
            }
            for(std::vector<string>::iterator it = tmp.begin(); it != tmp.end(); it++)
            {
                v.push_back("j" + *it);
                v.push_back("k" + *it);
                v.push_back("l" + *it);
            }
            break;
        case '6':
            if(tmp.size() == 0)
            {
                v.push_back("m");
                v.push_back("n");
                v.push_back("o");
            }
            for(std::vector<string>::iterator it = tmp.begin(); it != tmp.end(); it++)
            {
                v.push_back("m" + *it);
                v.push_back("n" + *it);
                v.push_back("o" + *it);
            }
            break;
        case '7':
            if(tmp.size() == 0)
            {
                v.push_back("p");
                v.push_back("q");
                v.push_back("r");
                v.push_back("s");
            }
            for(std::vector<string>::iterator it = tmp.begin(); it != tmp.end(); it++)
            {
                v.push_back("p" + *it);
                v.push_back("q" + *it);
                v.push_back("r" + *it);
                v.push_back("s" + *it);
            }
            break;
        case '8':
            if(tmp.size() == 0)
            {
                v.push_back("t");
                v.push_back("u");
                v.push_back("v");
            }
            for(std::vector<string>::iterator it = tmp.begin(); it != tmp.end(); it++)
            {
                v.push_back("t" + *it);
                v.push_back("u" + *it);
                v.push_back("v" + *it);
            }
            break;
        case '9':
            if(tmp.size() == 0)
            {
                v.push_back("w");
                v.push_back("x");
                v.push_back("y");
                v.push_back("z");
            }
            for(std::vector<string>::iterator it = tmp.begin(); it != tmp.end(); it++)
            {
                v.push_back("w" + *it);
                v.push_back("x" + *it);
                v.push_back("y" + *it);
                v.push_back("z" + *it);
            }
            break;
    }
    return v;
}

int main(){
    std::vector<string> v = letterCombinations("2");
    for (std::vector<string>::iterator it=v.begin(); it != v.end(); it++)
    {
        cout<<*it<<'\t';
    }
    cout<<endl;
    return 0;
}