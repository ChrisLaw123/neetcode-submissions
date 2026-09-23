class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        std::sort(nums.begin(), nums.end());

        for (int i{}; i < nums.size(); i++) {
            int target = -1 * nums[i];

            int l{i + 1}, r = nums.size() - 1;

            while (l < r) {
                if (nums[l] + nums[r] > target) {
                    r--;
                } else if (nums[l] + nums[r] < target) {
                    l++;
                } else {
                    vector<int> x = {nums[i], nums[l], nums[r]};
                    res.push_back(x);
                    l++;
                    while (l <= r && nums[l -1] == nums[l]) {
                        l++;
                    }
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                i++;
            }
        }

        return res;
    }
};
