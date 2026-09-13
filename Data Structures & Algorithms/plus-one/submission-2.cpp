class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        bool carry{true};
        for (int i = digits.size() - 1; i >= 0; i--) {
            if(digits[i] + 1 == 10 && carry) {
                res.insert(res.begin(), 0);
            } else {
                if (carry) {
                    res.insert(res.begin(), digits[i] + 1);
                } else {
                    res.insert(res.begin(), digits[i]);
                }
                carry = false;
            }
        }

        if (carry) {
            res.insert(res.begin(), 1);
        }

        return res;
    }
};
