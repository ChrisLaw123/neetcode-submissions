class Solution {
public:
    int findMin(vector<int> &nums) {
        int l{}, r = nums.size() - 1;
        int num = INT_MAX;

        while (l <= r) {
            int mid = l + (r - l)/2;
            if (nums[l] < nums[r]) {
                num = min(num, nums[l]);
            }

            if (nums[mid] >= nums[l]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
            num = min(num, nums[mid]);
        }
        if (nums[nums.size()-1] > nums[0]) return nums[0];
        return num;
    }
};
