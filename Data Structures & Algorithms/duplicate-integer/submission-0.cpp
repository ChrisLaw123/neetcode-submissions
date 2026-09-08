class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> res;
        int size = nums.size();
        for (int i{}; i < size; i++) {
            if (res.contains(nums[i])){
                return true;
            } else {
                res.insert(nums[i]);
            }
        }
        return false;
    }
};