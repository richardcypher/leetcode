/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年12月22日 星期二 19时13分30秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

int maxProduct(vector<string>& words){
    if(words.empty())
        return 0;
    vector<int> nums(words.size(), 0);
    int j = 0, bit = 0;
    for(int i = 0; i < words.size(); i++){
        for(j = 0; j < words[i].length(); j++){
            bit = 1<<(words[i][j] - 'a');
            nums[i] |= bit;
        }
    }
    int max = 0, length = 0;
    for(int i = 0; i < nums.size() - 1; i++){
        for(j = i + 1; j < nums.size(); j++){
            length = words[i].length() * words[j].length();
            if((nums[i] & nums[j]) == 0) {
                if(length > max)
                    max = length;
            }
        }
    }
    return max;
}

int main(){
    string arr[] = {"abcw","baz","foo","bar","xtfn","abcdef"};
    vector<string>v(arr, arr + sizeof(arr)/sizeof(arr[0]));
    cout<<maxProduct(v)<<endl;
}
