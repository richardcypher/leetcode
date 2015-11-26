#include<iostream>
using namespace std;

bool isvalid(string& num, int begin, int end) {
    int start1 = 0, end1 = begin - 1, start2 = begin, end2 = end, index = end + 1, length = num.length();
    string next, overflow;
    int i, j, cbit, num1, num2;
    char ch;
    while(index < length) {
        i = end1;
        j = end2;
        next = "0";
        while(i >= start1 || j >= start2) {
            num1 = 0;
            num2 = 0;
            if(i >= start1)
                num1 = num[i] - '0';
            if(j >= start2)
                num2 = num[j] - '0';
            cbit = num1 + num2 + (next[0] - '0');
            if(cbit <= 9) {
                ch = cbit + '0';
                next[0] = ch;
                next = "0" + next;
            }
            else {
                ch = cbit - 10 + '0';
                next[0] = ch;
                next = "1" + next;
            }
            i--;
            j--;
        }
        if(next[0] == '0')
            next = next.substr(1);
        for(i = index; i < index + next.length(); i++){
            if(num[i] != next[i - index]) {
                return false;
            }
        }
        start1 = start2;
        end1 = end2;
        start2 = end2 + 1;
        end2 = start2 + next.length() - 1;
        index = end2 + 1;
    }
    return true;
}

bool isAdditiveNumber(string num) {
    if(num.length() < 3)
        return false;
    int length = num.length(), begin = 1, end;
    for(; begin <= length/3; begin++) {
        for(end = begin; end < (length + begin) / 2; end++) {
            if(num[begin] == '0' && end != begin)
                continue;
            if(isvalid(num, begin, end))
                return true;
        }
    }
    return false;
}

int main(){
    cout<<isAdditiveNumber("12012122436")<<endl;
}
