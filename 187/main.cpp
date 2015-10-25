/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月23日 星期五 20时30分57秒
    将A,C,G,T对应4个数字1,2,3,4.10个字母对应20位的整数,用map来存储是否已经
    出现了这个数字
************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<bitset>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    vector<string> result;
    if(s.empty())
        return result;
    map<char, int> dict;
    map<int, bool> m;
    dict['A'] = 0;//00
    dict['C'] = 1;//01
    dict['G'] = 2;//10
    dict['T'] = 3;//11
    int length = s.length(), bit = 0;
    int zeros = ~(3<<18);
    for(int i = 0; i < length - 9; i++) {
        if(i == 0) {
            for(int j = 0; j < 10; j++) {
                bit <<= 2;
                bit |= dict[s[j]];
            }
        }
        else {
            bit &= zeros;
            bit <<= 2;
            bit |= dict[s[i + 9]];
        }
        // cout<<s.substr(i,10)<<'\t'<<bitset<32>(bit)<<endl;
        if(m.find(bit) != m.end() && m[bit]) {
            result.push_back(s.substr(i, 10));
            m[bit] = false;
        }
        else if(m.find(bit) == m.end()){
            m[bit] = true;
        }
    }
    return result;
}

int main() {
/*    int x = ~(3 << 18);
    cout<<bitset<32>(x)<<endl;*/
    vector<string> v = findRepeatedDnaSequences("TGCTCCTGTCACAACTTCTTTACCAGCCTGTTTTTCTAGAGTCGGCTCAAAACCTGCCTTTATGCGCAGCTGTCCACGAGAATTTCATGTTATCGAGGACCGCGATATACCCAATCGCGCGCCCCAGAAAAAAGAGTCTTACCAGATGTATACGGTGACGACCCAGTGGGTAAGACCGCTCTGCTCAGCGACCCGTCCATACCCACAGTCAGCCATGTGTGACATATCAGCGTGCATTCTTGATCTGTATGGGTGCGCTGCCCCCGCACTTGATGGGGTATGTGATGACTCCGCTCGGTAAGCAAGACCCTGGGGGTTCGGACGTAGGGTATACCCGAACTTCACGTATGCGGACACCAACGCACGTGCCAATTTATCTAACGTATGTCTCCATGCCGCCCAGAAGGTTAAAGTGGACCGCCGTTCGTATACTGTTTCTGCAATTGTGTGCGGCAGCACCAGGTAGAGAGCATTCTATTTCGCTAGCTAGTAAATCTACTTCACCGAGTCTGGAAGCTCCAATCGCTGTTTACAAACTTTTTGCCCCTGCGTGGGTCAGGCCATGTCCCGTTCCCGAGGATTCTAGCACTGACCTAGCCCTATATCACGAGCCGGGTTTTCTTAAAATAGAGATCGGGACGTTAAGGTCTTATGAACGGCTTCAGCTATCTTCCGCTTACCAACTGAGCCGAACTATCTCCGGGTGTTACATGGATCCTAAAATGCTCTCCAATTTTGCCCCTGCATGGTATTTCTCTTGAGACTACTGGATCTACCTGGGTTGTGCATGTTTCGTGTCTCTTCCGACGTTCGACAATTGGGGGCGACGCTTTAAGTTCTACTACGGTGAGATGCACATCCCACGGACGCCCTTTTCCTTTGGCTCTTCCTACGTTCGCGAGCGGTCCTGTAGGACAGTTGCTTTATGCCAACTTTTACGAGGGTGGAATACAGTATCGCCATGACACTCTGAAAAAGGATGGAAGACCTGAGATTCACC");
    for(auto s : v) {
        cout<<s<<endl;
    }
    return 0;
}
