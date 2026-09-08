class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        vector<int> res;

        for (int i{}; i < nums.size(); i++) {
            int key = target - nums[i];

            if (map.contains(key)) {
                res.push_back(map[key]);
                res.push_back(i);
                return res;
            } else {
                map[nums[i]] = i;
            }
        }
        return res;
    }
};
