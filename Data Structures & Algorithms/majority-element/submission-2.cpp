class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0];
        int numcount = 1;

        for (int i{1}; i < nums.size(); i++) {
            if (numcount == 0) {
                num = nums[i];
                numcount++;
            } else if (nums[i] == num) {
                numcount++;
            } else {
                numcount--;
            }
        }

        return num;
    }
};