class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        bool carry{true};
        for (int i = digits.size() - 1; i >= 0; i--) {
            if(digits[i] + 1 == 10 && carry) {
                res.push_back(0);
            } else {
                if (carry) {
                    res.push_back(digits[i] + 1);
                } else {
                    res.push_back(digits[i]);
                }
                carry = false;
            }
        }

        if (carry) {
            res.push_back(1);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
