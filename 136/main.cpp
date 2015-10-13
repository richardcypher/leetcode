#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int num = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        num = num ^ nums[i];
    }
    return num;
}

int main() {
    return 0;
}