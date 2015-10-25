/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月25日 星期日 12时31分33秒
 ************************************************************************/

#include<iostream>
#include<cstdint>
#include<bitset>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t t = 0, tmp = 1;
    for(int i = 0; i < 32; i++) {
        tmp = 1;
        tmp <<= i;
        t |= ((n & tmp) >> i) << (31 - i);
    }
    return t;
}

int main() {
    uint32_t r = reverseBits(4);
    cout<<bitset<32>(r)<<endl;
    return 0;
}
