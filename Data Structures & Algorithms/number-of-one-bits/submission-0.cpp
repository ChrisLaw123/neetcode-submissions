class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t x{1};
        int res{};
        for (int i{}; i < 32; i++) {
            if (n & x) {
                res++;
            }
            x = x<<1;
        }

        return res;
    }
};
