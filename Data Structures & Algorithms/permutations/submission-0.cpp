class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> used(nums.size(), false);

        // Keep these across iterations
        vector<int> permutation;
        stack<int> chosen;
        int next = 0;

        while (true) {
            if (permutation.size() == nums.size()) {
                res.push_back(permutation);
            } else {
                // Find the next available candidate
                while (next < nums.size() && used[next]) {
                    next++;
                }

                if (next < nums.size()) {
                    permutation.push_back(nums[next]);
                    used[next] = true;
                    chosen.push(next);

                    next = 0;
                    continue; // Go deeper before backtracking
                }
            }

            // Full permutation or no remaining candidates
            if (chosen.empty()) break;

            int last = chosen.top();
            chosen.pop();

            permutation.pop_back();
            used[last] = false;

            next = last + 1;
        }

        return res;
    }
};