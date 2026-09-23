class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res{}; 
        std::unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;
        int sum;
        for (auto num : nums) {
            sum += num;
            int x = sum - k;
            res += prefixSum[x];
            prefixSum[sum]++;
        } 
        return res;
    }
};