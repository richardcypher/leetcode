/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月23日 星期一 18时45分13秒
 ************************************************************************/

#include<iostream>
using namespace std;

bool canWinNim(int n) {
    return n % 4 != 0;
}

int main(){
    cout<<canWinNim(1348820612)<<endl;
}
