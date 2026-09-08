class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res{};
        for (int i{}; i < nums.size(); i ++) {
            res^=nums[i];
            res^=i;
        }

        return res ^= nums.size();

    }
};
