class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l{}, r = heights.size() - 1, max{};

        while (l <= r) {
            if ((r - l) * min(heights[l], heights[r]) > max){
                max = (r - l) * min(heights[l], heights[r]);
            }

            if(heights[l] <= heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return max;

    }
};
