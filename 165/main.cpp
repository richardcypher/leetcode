/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月18日 星期日 12时37分21秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int compareVersion(string version1, string version2) {
    int v1 = 0, v2 = 0;
    int index1 = -1, index2 = -1, length1 = version1.length(), length2 = version2.length();
    while(index1 < length1 || index2 < length2) {
        index1++;
        index2++;
        v1 = 0;
        v2 = 0;
        for(; index1 < length1 && version1[index1] != '.'; index1++)
            v1 = v1 * 10 + (version1[index1] - '0');
        for(; index2 < length2 && version2[index2] != '.'; index2++)
            v2 = v2 * 10 + (version2[index2] - '0');
        if(v1 < v2)
            return -1;
        else if(v1 > v2)
            return 1;
    }
    return 0;
}

int main() {
    cout<<compareVersion("1", "0")<<endl;
    return 0;
}
