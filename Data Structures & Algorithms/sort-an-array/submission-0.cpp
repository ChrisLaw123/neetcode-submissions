class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (int i{}; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] < nums[i]) swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};