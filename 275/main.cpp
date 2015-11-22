/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月22日 星期日 22时17分01秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int hIndex(vector<int>& citations) {
    int n = citations.size() - 1, h = 0;
    int low = 0, high = n, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if(n - mid + 1 == citations[mid]) 
            return n - mid  +1;
        else if(n - mid + 1 < citations[mid]) {
            high = mid - 1;
            h = n - mid + 1;
        }
        else 
            low = mid + 1;
    }
    return h;
}

int main(){
    int arr[] = {0, 1, 4, 5, 6};
    vector<int> cs(arr, arr + sizeof(arr) / sizeof(arr[0]));
    cout<<hIndex(cs)<<endl;
}
