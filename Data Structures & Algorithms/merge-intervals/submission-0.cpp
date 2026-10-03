class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //lets sort the intervals by start time
        std::sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a[0] < b[0];
        });

        vector<vector<int>> res;
        for (auto interval : intervals) {
            if (res.empty()) {
                res.push_back(interval);
            } else if (interval[0] <= res[res.size() - 1][1]) {
                if (interval[1] > res[res.size() - 1][1]) res[res.size() - 1][1] = interval[1];
            } else {
                res.push_back(interval);
            }
        }

        return res;
    }
};
