/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月26日 星期一 20时56分54秒
 ************************************************************************/

#include<iostream>
using namespace std;

/*bool isPrime(int n) {
    if(n <= 1)
        return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

int countPrimes(int n) {
    int cnt = 0;
    for(int i = 2; i < n; i++ ) {
        if(isPrime(i))
            cnt++;
    }
    return cnt;
}*/
int countPrimes(int n) {
    bool *isPrime = new bool[n];
    for(int i = 2; i < n; i++)
        isPrime[i] = true;
    for(int i = 2; i * i < n; i++) {
        if(!isPrime[i])
            continue;
        for(int j = i * i; j < n; j += i)
            isPrime[j] = false;
    }
    int cnt = 0;
    for(int i = 2; i < n; i++)
        if(isPrime[i])
            cnt++;
    return cnt;
}
int main() {
    return 0;
}
