class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i{}; i <= n; i++) {
            int count{};
            int x{1};

            for(int j{}; j < 10; j++) {
                if (i & x) {
                    count++;
                }
                x = x<<1;
            }

            res.push_back(count);
        }

        return res;
    }
};
