class Solution {
public:
    int trap(vector<int>& height) {
        int left{}, right = height.size() - 1;

        int lmax{height[left]}, rmax{height[right]}, curr{}, total{};
        while (left <= right) {
            if(lmax < rmax) {
                curr = height[left];
                if(curr > lmax) {
                    lmax = curr;
                    left++;
                } else {
                    total += lmax-curr;
                    left++;
                }
            } else {
                curr = height[right];
                if(curr > rmax) {
                    rmax = curr;
                    right--;
                } else {
                    total += rmax-curr;
                    right--;
                }
            }
        }

        return total;
     }
};
