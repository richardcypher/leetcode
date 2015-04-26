#include <iostream>
#include <algorithm>
using namespace std;
int maxArea(vector<int> &height) {
    int low = 0, high = height.size() - 1, ma = 0;
    while(low < high) {
        ma = max(ma, (high - low) * min(height[low], height[high]));
        if(height[low] < height[high])
            low++;
        else
            high--;
    }
    return ma;
}
int main(){
}