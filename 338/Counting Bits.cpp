class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> rst(num + 1, 0);
        if(num < 0)
            return rst;
        int j;
        for(int i = 2; i <= num; i <<= 1) {
            for(j = 0; i + j <= num && j <= i - 2; j += 2) {
                rst[i + j] = 1 + rst[j];
            }
        }
        for(int i = 1; i <= num; i += 2) {
            rst[i] = rst[i - 1] + 1;
        }
        return rst;
    }
};
