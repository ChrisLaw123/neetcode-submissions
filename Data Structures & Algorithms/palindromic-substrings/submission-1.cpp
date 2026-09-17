class Solution {
public:
    int countSubstrings(string s) {
        int res{};
        //for every starting point
        for (int i{}; i < s.size(); i++) {
            res++;
            int l{i-1}, r{i+1};
            //l + r odd
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                res++;
                l--;
                r++;
            }
            // l r even
            l = i;
            r = i+1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                res++;
                l--;
                r++;
            }
            
        }
        return res;
    }
};
