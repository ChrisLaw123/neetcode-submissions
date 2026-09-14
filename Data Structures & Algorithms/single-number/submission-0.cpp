class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res{};
        for (int n: nums) {
            res ^= n;
        }
        return res;
    }
};
