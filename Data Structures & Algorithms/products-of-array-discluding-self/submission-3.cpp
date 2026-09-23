class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 0) return res;

        int total = nums[0];

        int found0{};
        if (nums[0] == 0) {
            found0 = true;
        }
        for (int i{1}; i < nums.size(); i++) {
            if (nums[i] != 0) {
                if (total == 0) {
                    total += nums[i];
                } else{
                    total *= nums[i];
                }           
            } else {
                found0++;
            }
        }

        for (int i{}; i < nums.size(); i++) {
            if(found0 > 1) {
                res.push_back(0);
            } else if(nums[i] == 0) {
                res.push_back(total);
            } else if (found0 == 1){
                res.push_back(0);
            } else {
                res.push_back(total/nums[i]);
            }
        }

        return res;
    }
};
