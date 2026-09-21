class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> set;

        for (auto num : nums) {
            set.insert(num);
        }

        //find starting point, then search

        int longest{};
        for (auto num : set) {
            int curr{1};
            if(!set.contains(num-1)) {
                //this number is a starting point
                for(int i{num}; set.contains(i+1); i++) {
                    curr++;
                }

            }
            if (curr > longest) longest = curr;
        }

        int res{};
        return longest;
    }
};
