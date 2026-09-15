class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> window;

        // lets initialize the first window before we start shifting
        for (int i{}; i < k; i++) {
            while (!window.empty() && nums[i] > nums[window.back()]) {
                window.pop_back();
            }
            window.push_back(i);
        }
        res.push_back(nums[window.front()]);

        for (int i{1}; i <= nums.size() - k; i++) {
            while (!window.empty() && window.front() < i) {
                window.pop_front();
            }
            while (!window.empty() && nums[i + k - 1] > nums[window.back()]) {
                window.pop_back();
            }
            window.push_back(i + k - 1);
            res.push_back(nums[window.front()]);
        }

        return res;
    }
};
