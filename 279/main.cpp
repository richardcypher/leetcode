/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月22日 星期日 23时10分55秒
 ************************************************************************/

#include<iostream>
using namespace std;

int numSquares(int n) {
    int *num = new int[n + 1];
    num[0] = 0;
    num[1] = 1;
    for(int i = 2; i <= n; i++) {
        num[i] = i;
        for(int k = 1; k * k <= i; k++) {
            if(num[i - k * k] + 1 < num[i])
                num[i] = num[i - k * k] + 1;
        }
    }
    int r = num[n];
    delete []num;
    return r;
}

int main(){}
