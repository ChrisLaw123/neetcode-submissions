class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l{};
        for (int r{};  r < nums.size(); r++) {
            if (nums[r] != 0) {
                swap(nums[l], nums[r]);
                l++;
             
            }

        }
    }
};