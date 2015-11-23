/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月23日 星期一 15时35分31秒
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;

string convert(int num, map<int, string>& words) {
    string str = "";
    int left = num % 100;
    num /= 100;
    if(num != 0) {
        str = words[num] + " " + words[100] + " ";
    }
    if(left >= 20) {
        num = left % 10;
        left /= 10;
        left *= 10;
        str += words[left] + " " + words[num];
    }
    else {
        str += words[left];
    }
    str.erase(str.find_last_not_of(" ") + 1);
    return str;
}

string numberToWords(int num) {
    if(num == 0)
        return "Zero";
    string str = "";
    map<int, string> words;
    words[0] = "";
    words[1] = "One"; words[2] = "Two"; words[3] = "Three"; words[4] = "Four"; words[5] = "Five";
    words[6] = "Six"; words[7] = "Seven"; words[8] = "Eight"; words[9] = "Nine"; words[10] = "Ten";
    words[11] = "Eleven"; words[12] = "Twelve"; words[13] = "Thirteen"; words[14] = "Fourteen"; words[15] = "Fifteen";
    words[16] = "Sixteen"; words[17] = "Seventeen"; words[18] = "Eighteen"; words[19] = "Nineteen"; words[20] = "Twenty";
    words[30] = "Thirty"; words[40] = "Forty"; words[50] = "Fifty"; words[60] = "Sixty"; words[70] = "Seventy"; words[80] = "Eighty";
    words[90] = "Ninety"; words[100] = "Hundred"; words[1000] = "Thousand"; words[1000000] = "Million";words[1000000000] = "Billion";
    int bit = 1;
    while(num > 0) {
        int left = num % 1000;
        num /= 1000;
        if(left != 0) {
            if(bit != 1)
                str = convert(left, words) + " " + words[bit] + " " + str;
            else
                str = convert(left, words) + " " + str;
        }
        bit *= 1000;
    }
    str.erase(str.find_last_not_of(" ") + 1);
    return str;
}

int main(){
    cout<<numberToWords(1000000)<<":end"<<endl;
}
