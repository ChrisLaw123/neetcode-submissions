class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left{1};
        int right{1};
        for (int i{}; i < piles.size(); i++) {
            right = max(right, piles[i]);
        }
        
        int mid{};
        while (left < right) {
            mid = left + (right - left)/2;
            int count{};
            for (int i{}; i < piles.size(); i++) {
                count += ceil(static_cast<double>(piles[i])/mid);
            }
            if (count > h) {
                //too slow
                left = mid + 1;
            } else {
                //fast enough
                right = mid;
            } 
        }

        return left;
        
    }
};
