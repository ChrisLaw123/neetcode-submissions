class Solution {
public:
    int reverse(int x) {
        int res{}, max = INT_MAX, min = INT_MIN;

        while (x != 0) {
            if (res > max/10 || res < min/10) {
                return 0;
            } else {
                
                res *= 10;
                res += x%10;
                x/=10;
            }
        }
        return res;
    }
};
