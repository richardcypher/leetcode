#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int trap(vector<int>& height) {
    if(height.empty())
        return 0;
    int index = 0, vol = 0;
    while(height[index] <= 0)
        index++;
    while(index < height.size() - 1 && height[index] < height[index + 1])
        index++;
    stack<int> st;
    st.push(index);
    index++;
    int bottom = 0;
    bool isbottom = true;
    while(index < height.size()) {
        if(height[index] < height[index - 1]) {
            st.push(index);
            bottom = height[index];
            isbottom = true;
        }
        else if(height[index] == height[index - 1]) {
            st.pop();
            st.push(index);
        }
        else {
            if(isbottom) {
                st.pop();
                isbottom = false;
            }
            while(!st.empty() && height[st.top()] <= height[index]) {
                int left = st.top();
                st.pop();
                vol += (height[left] - bottom) * (index - left - 1);
                bottom = height[left];
            }
            if(!st.empty() && height[st.top()] > height[index]) {
                vol += (index - st.top() - 1) * (height[index] - bottom);
                bottom = height[index];
            }
            if(index < height.size()  -1 && height[index] >= height[index + 1])
                st.push(index);
        }
        index++;
    }
    return vol;
}

int main() {
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    int vol = trap(v);
    cout<<vol<<endl;
    return 0;
}