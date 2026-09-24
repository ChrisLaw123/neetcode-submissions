class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int x = nums[0];
        std::unordered_set<int> found;
        found.insert(x);
        for (int i{1}; i < nums.size(); i++) {
            if (found.contains(x ^ nums[i])) return nums[i];
            found.insert(x ^ nums[i]);
        }

        return x;
    }

};
