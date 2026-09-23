class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res (temperatures.size(), 0);
        //temp, index
        stack<pair<int, int>> s;

        for (int i{}; i < temperatures.size(); i++) {
            int currTemp = temperatures[i];
            if (s.empty() || s.top().first >= currTemp) {
                s.push({currTemp, i});
            } else {
                //keep popping until curr < temp
                while (!s.empty() && s.top().first < currTemp) {
                    res[s.top().second] = i - s.top().second;
                    s.pop();
                }
                s.push({currTemp, i});
            }
        }

        return res;
    }
};
