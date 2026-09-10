class Solution {
public:
    bool isHappy(int n) {
        if (n == 1) {
            return true;
        }

        unordered_set<int> seen;

        while (n != 1) {
            if (seen.contains(n)) {
                return false;
            } else {
                seen.insert(n);
            }
            int x{};

            while (n>0) {
                x += (n%10) * (n%10);
                n/= 10;
            }

            n = x;
        }
        return true;


    }
};
