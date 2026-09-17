class Solution {
public:
    string longestPalindrome(string s) {
        string max{};
        //for every starting point
        for (int i{}; i < s.size(); i++) {
            string res{};
            res.insert(res.begin(), s[i]);
            int l{i-1}, r{i+1};
            //l + r odd
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                res.insert(res.begin(), s[l]);
                res.push_back(s[r]);
                l--;
                r++;
            }
            if (res.size() > max.size()) max = res;
            // l r even
            l = i;
            r = i+1;
            res = {};
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                res.insert(res.begin(), s[l]);
                res.push_back(s[r]);
                l--;
                r++;
            }
            if (res.size() > max.size()) max = res;
            
        }
        return max;
    }
};
