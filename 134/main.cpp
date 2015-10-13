#include <vector>
#include <iostream>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    if(gas.empty())
        return -1;
    int start = 0, cur = 0, gasleft = 0;
    while(true) {
        gasleft += gas[cur] - cost[cur];
        if(cur == gas.size() - 1)
            cur = 0;
        else
            cur++;
        if(cur == start && gasleft >= 0) 
            break;
        while(gasleft < 0 && start < gas.size()) {
            gasleft += cost[start] - gas[start];
            start++;
            if(start == cur)
                break;
        }
        if(start == gas.size())
            return -1;
    }
    return start;
}

int main() {
    int arr1[] = {6,0,1,3,2}, arr2[] = {4,5,2,5,5};
    vector<int> gas(arr1, arr1 + sizeof(arr1)/sizeof(arr1[0])), cost(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
    int start = canCompleteCircuit(gas, cost);
    cout<<start<<endl;
    return 0;
}