/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月25日 星期日 13时01分55秒
 ************************************************************************/

#include<iostream>
#include<cstdint>
using namespace std;

/*
while (n){
        count++;   
        n&=n-1;
}
*/

int hammingWeight(uint32_t n) {
    int w = 0;
    uint32_t tmp;
    for(int i = 0; i < 32; i++) {
        tmp = 1;
        tmp <<= i;
        if((tmp & n) != 0)
            w++;
    }
    return w;
}
int main() {
    cout<<hammingWeight(  4294967295)<<endl;
    return 0;
}
