class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int res{3}, prev{2};

        for (int i{3}; i < n; i++) {
            int temp{res};
            res = res + prev;
            prev = temp;
        }

        return res;

    }
};
