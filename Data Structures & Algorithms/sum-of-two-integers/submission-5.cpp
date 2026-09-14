class Solution {
public:
    int getSum(int a, int b) {
        int sum{}, track{};
        bool carry{};
        for (int i{}; i < 32; i ++) {
            sum = sum | (((a & 1) ^ (b & 1) ^ carry) << track);

            if ( ((a & 1) && (b & 1)) || ((a & 1) && carry) || (carry && (b & 1)) ) {
                carry = true;
            } else {
                carry = false;
            }
            
            a = a>>1;
            b = b>>1;
            track++;
        }

        return sum;
    }
};
