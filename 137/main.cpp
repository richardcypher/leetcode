#include <vector>
using namespace std;
//每位相加，如果对应位的和不能被3整除，则num的这一位为1 
int singleNumber(vector<int>& nums) {
    int bit = 0, sum = 0, num = 0;
    while(bit < 32) {
        sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += (nums[i] >> bit) & 1;
        }
        if(sum % 3 != 0)
            num += 1<<bit;
        bit++;
    }
    return num;
}

int main() {
    return 0;
}
