class Solution {
public:
    int search(vector<int>& nums, int target) {
        //find the index where the array splits. must determine which half the target is in, 
        //then perform bs on that half
        int l{}, r = nums.size() - 1;
        int splitIndex{};
        bool splitFound = false;

        //correct order, no split
        if (nums[l] <= nums[r]) {
            splitFound = true;
        }
        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r]) {
                l = mid + 1;  // Minimum is to the right
            } else {
                r = mid;      // mid could be the minimum
            }
        }

        splitIndex = l;

        if (target == nums[splitIndex]) {
            return splitIndex;
        } else if (target <= nums.back()){
            //search upper half
            l = splitIndex + 1;
            r = nums.size() -1;
            
            while (l <= r) {
                int mid = l + (r - l)/2;

                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] > target) {
                    r = mid - 1;
                } else {
                    l =  mid + 1;
                }
            }
        } else {
            //search lower half
            l = 0;
            r = splitIndex - 1;

            while (l <= r) {
                int mid = l + (r - l)/2;

                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] > target) {
                    r = mid - 1;
                } else {
                    l =  mid + 1;
                }
            }
        }

        return -1;
    }
};
