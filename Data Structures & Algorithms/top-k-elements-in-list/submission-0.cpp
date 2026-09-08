class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> map;

        for(int i : nums) {
            map[i] +=1;
        }

        //nums.size() + 1 is the maximum freq a number can have
        vector<vector<int>> bucketsort(nums.size() + 1);

        for (auto [num, freq] : map) {
            bucketsort[freq].push_back(num);
        }

        for (int i = nums.size(); i > 0; i--) {
            for (int num : bucketsort[i]) {
                res.push_back(num);

                if(res.size() == k) {
                    return res;
                }
            }
        }

    return res;
    }
};
