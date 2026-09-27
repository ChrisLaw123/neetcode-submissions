class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int origSize = nums.size();
        for (int i{}; i < origSize; i++) {
            nums.push_back(nums[i]);
        }
        return nums;
    }
};