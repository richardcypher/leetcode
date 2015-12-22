/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月22日 星期二 19时55分08秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

int bulbSwitch1(int n){
    if(n < 1)
        return 0;
    else if(n == 1)
        return 1;
    int *bulbs = new int[n];
    for(int i = 0; i < n; i++)
        bulbs[i] = 1;
    int j = 1;
    for(int i = 2; i <= n; i++){
        for(j = 1; j <= n / i; j++){
            bulbs[j * i - 1] ^= 1;
        }
    }
    int bs = 0;
    for(int i = 0; i < n; i++)
        bs += bulbs[i];
    return bs;
}

int bulbSwitch(int n){
    return sqrt(n);
}

int main(){
    cout<<bulbSwitch(9999999)<<endl;
}
