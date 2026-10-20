class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max{};
        int count{};
        for (int& num : nums) {

            if (num == 1) {
                count++;
            } else {
                count = 0;
            }
 
            if (count > max) max = count;
        }
        return max;
    }
};