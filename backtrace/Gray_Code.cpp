/*
**关键在于，如何通过前边的码构建后边的码。
**前半部分在前边补0，后半部分在最高位填1，然后将上次码的数逆序加进来。
*/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> rl;
        
        if (n == 0) {
            rl.push_back(0);
            return rl;
        }
        
        rl.push_back(0);
        rl.push_back(1);
        
        for (int i = 1; i < n; i++) {
            for (int j = (1<<i) - 1; j >= 0; j--) {
                rl.push_back((1<<i) + rl[j]);
            }
        }
        return rl;
    }
};