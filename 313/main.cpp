/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月06日 星期日 11时17分04秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int nthSuperUglyNumber(int n, vector<int>& primes) {
    int k = primes.size();
    if(k < 1)
        return 0;
    vector<int> l(k, 1);
    vector<int>  index(k, 0);
    vector<int> num(n);
    int j = 0;
    for(int i = 0; i < n; i++) {
        num[i] = l[0];
        for(j = 1; j < k; j++){
            if(num[i] > l[j])
                num[i] = l[j];
        }
        for(j = 0; j  < k; j++) {
            if(l[j] == num[i])
                l[j] = primes[j] * num[index[j]++];
        }
    }
    return num[n - 1];
}

int main() {
    int arr[] = {2,3,5,13,19,29,31,41,43,53,59,73,83,89,97,103,107,109,127,137,139,149,163,173,179,193,197,199,211,223,227,229,239,241,251,257,263,269,271,281,317,331,337,347,353,359,367,373,379,389,397,409,419,421,433,449,457,461,463,479,487,509,521,523,541,547,563,569,577,593,599,601,613,619,631,641,659,673,683,701,709,719,733,739,743,757,761,769,773,809,811,829,857,859,881,919,947,953,967,971};
    vector<int> p(arr, arr  + sizeof(arr)/sizeof(arr[0]));
    cout<<nthSuperUglyNumber(200000, p)<<endl;
}
