class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int l{}, r = numbers.size() - 1;
        int sum = numbers[l] + numbers[r];

        while (sum != target) {
            if (sum > target) {
                r--;
            } else {
                //sum < target
                l++;
            }
            sum = numbers[l] + numbers[r];
        }

        res.push_back(l+1);
        res.push_back(r+1);
        return res;
    }
};
