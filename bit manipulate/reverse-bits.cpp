class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res += ((n>>(31-i))&1)<<i;
        }
        return res;
    }
};