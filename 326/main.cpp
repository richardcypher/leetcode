/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月10日 星期日 17时05分38秒
 ************************************************************************/

#include<iostream>
using namespace std;
bool isPowerOfThree(int n){
    if(n == 1)
        return true;
    else if(n < 3)
        return false;
    if(n % 3 != 0)
        return false;
    return isPowerOfThree(n / 3);
}

int main() {
    
}
