class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> combs = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                             {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                             {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> res;
        if (digits.size() == 0) return res;
        backtracking(combs, digits, res, "");

        return res;
    }

    void backtracking(unordered_map<char, string> combs, string digits, vector<string>& res,
                      string curr) {
        // insert the starting points
        if (curr.size() == digits.size()) {
            res.push_back(curr);
            return;
        }
        int i = curr.size();
        // now we iterate through each digits combinatins
        for (int j = 0; j < combs.at(digits[i]).size(); j++) {
            curr += combs.at(digits[i])[j];
            backtracking(combs, digits, res, curr);
            curr.erase(curr.end() - 1);
        }
    }
};
