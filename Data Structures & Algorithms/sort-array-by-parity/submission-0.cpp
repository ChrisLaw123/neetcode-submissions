class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l{};

        for (int r{}; r < nums.size(); r++) {
            if (nums[r] %2 == 0) {
                swap(nums[l], nums[r]);
                l++;
            }
        }
        return nums;

    }
};