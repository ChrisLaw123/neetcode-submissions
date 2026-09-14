class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev{};
        
        for (int i{}; i < 31; i++) {
            rev = rev | (n & 1);
            n = n >> 1;
            rev = rev << 1;
        }
        rev = rev | (n & 1);
        return rev;
    }
};
