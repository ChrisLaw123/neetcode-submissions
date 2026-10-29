class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l{}, r = nums.size() - 1;
        int res = nums.size();
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (target == nums[mid]) return mid;

            if (target > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
                res = mid;
            }
        }

        return res;
    }
};