/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月15日 星期日 10时22分03秒
 ************************************************************************/

#include<iostream>
using namespace std;

int countDigitOne(int n) {
    if(n <= 0)
        return 0;
    int total1 = 0, lastnum, numof1, origin = n, num10 = 1;
    while(n > 0){
        numof1 = 0;//1 in this bit
        lastnum = n % 10;
        n /= 10;
        if(lastnum == 0) {
            if(num10 != 1)
                numof1 = n * num10;
            else
                numof1 = n;
        }
        else {
            if(n != 0)
                numof1 = (n + 1) * (origin - n * num10 * 10 + 1);
            else
                numof1 = num10;
        }
        num10 *= 10;
        total1 += numof1;
    }
    return total1;
}

int main() {
    cout<<countDigitOne(20)<<endl;
}
