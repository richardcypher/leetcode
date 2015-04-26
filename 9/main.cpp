#include <iostream>
#include <math.h>
using namespace std;

bool isPalindrome(int x) {
    if(x == -2147483648ll)
        return false;
    if(x < 0)
        return false;
    else if(x == 0)
        return true;
    int start = 0,end = 0;
    while(x / (int)pow(10.0, start) != 0)
        start++;
    start--;
    while( ((x / (int)pow(10.0, start)  % 10)== ((x / (int)pow(10.0, end)) % 10 ) ) ){
        start--;
        end++;
        if(start <= end )
            return true;
    }
    return false;
}
int main(){
    cout<<boolalpha<<isPalindrome(0)<<endl;
    return 0;
}